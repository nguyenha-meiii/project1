#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <numeric> // Include for std::accumulate
#include <algorithm>

using namespace std;

struct Transaction
{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

bool isCycleUtil(string account, string startAccount, int k, unordered_map<string, vector<Transaction>> &graph, unordered_set<string> &visited, unordered_set<string> &recStack, unordered_map<string, unordered_map<int, bool>> &memo)
{
    if (k == 0 && account == startAccount)
    {
        return true;
    }

    if (visited.count(account))
    {
        return false;
    }

    if (memo[account].count(k))
    {
        return memo[account][k];
    }

    visited.insert(account);
    recStack.insert(account);

    for (const auto &transaction : graph[account])
    {
        if (isCycleUtil(transaction.to_account, startAccount, k - 1, graph, visited, recStack, memo))
        {
            memo[account][k] = true;
            return true;
        }
    }

    visited.erase(account);
    recStack.erase(account);

    memo[account][k] = false;
    return false;
}

bool isCycle(string account, int k, unordered_map<string, vector<Transaction>> &graph)
{
    unordered_set<string> visited;
    unordered_set<string> recStack;
    unordered_map<string, unordered_map<int, bool>> memo;
    return isCycleUtil(account, account, k, graph, visited, recStack, memo);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<Transaction> transactions;
    unordered_map<string, vector<Transaction>> graph;
    unordered_map<string, int> accountTotalMoney;

    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "#")
        {
            break;
        }

        istringstream iss(input);
        Transaction transaction;
        iss >> transaction.from_account >> transaction.to_account >> transaction.money >> transaction.time_point >> transaction.atm;
        transactions.push_back(transaction);
        graph[transaction.from_account].push_back(transaction);
        accountTotalMoney[transaction.from_account] += transaction.money;
    }

    string query;
    while (cin >> query && query != "#")
    {
        if (query == "?number_transactions")
        {
            cout << transactions.size() << endl;
        }
        else if (query == "?total_money_transaction")
        {
            int total = accumulate(transactions.begin(), transactions.end(), 0, [](int acc, const Transaction &transaction)
                                   { return acc + transaction.money; });
            cout << total << endl;
        }
        else if (query == "?list_sorted_accounts")
        {
            set<string> accounts;
            for (const auto &transaction : transactions)
            {
                accounts.insert(transaction.from_account);
                accounts.insert(transaction.to_account);
            }

            for (const auto &account : accounts)
            {
                cout << account << endl;
            }
        }
        else if (query == "?total_money_transaction_from")
        {
            string account;
            cin >> account;

            if (accountTotalMoney.count(account))
            {
                cout << accountTotalMoney[account] << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        else if (query == "?inspect_cycle")
        {
            string account;
            int k;
            cin >> account >> k;

            if (isCycle(account, k, graph))
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}
