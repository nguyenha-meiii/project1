#include <bits/stdc++.h>

#define int long long
using namespace std;

int INF = 1e9;

struct Order
{
    int price;
    int time;
};

bool sortOrder(Order a, Order b)
{
    if (a.time == b.time)
        return a.price < b.price;
    else
        return a.time < b.time;
}

int convertTime(string time)
{
    int hour = 10 * (time[0] - '0') + (time[1] - '0');
    int minute = 10 * (time[3] - '0') + time[4] - '0';
    int second = 10 * (time[6] - '0') + time[7] - '0';
    return hour * 3600 + minute * 60 + second;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string customerID;
    string productID;
    string shopID;
    string timePoint;
    Order order;
    vector<Order> orders;
    int number_order = 0;
    int total_revenue = 0;
    map<string, int> shop_revenue;
    map<string, map<string, int>> customer_shop_consume;

    while (true)
    {
        cin >> customerID;
        if (customerID == "#")
            break;
        cin >> productID >> order.price >> shopID >> timePoint;
        order.time = convertTime(timePoint);
        number_order++;
        total_revenue += order.price;
        shop_revenue[shopID] += order.price;
        customer_shop_consume[customerID][shopID] += order.price;
        orders.push_back(order);
    }
    sort(orders.begin(), orders.end(), sortOrder);
    string query;
    vector<pair<int, int>> prefix(orders.size() + 1);
    prefix[0].first = 0;
    prefix[0].second = 0;

    for (int i = 1; i <= orders.size(); i++)
    {
        prefix[i].first = orders[i - 1].time;
        prefix[i].second = orders[i - 1].price + prefix[i - 1].second;
    }

    while (true)
    {
        cin >> query;
        if (query == "#")
            break;
        if (query == "?total_number_orders")
            cout << number_order << endl;
        else if (query == "?total_revenue")
            cout << total_revenue << endl;
        else if (query == "?revenue_of_shop")
        {
            cin >> shopID;
            cout << shop_revenue[shopID] << endl;
        }
        else if (query == "?total_consume_of_customer_shop")
        {
            cin >> customerID;
            cin >> shopID;
            cout << customer_shop_consume[customerID][shopID] << endl;
        }
        else if (query == "?total_revenue_in_period")
        {
            string time_begin, time_end;
            cin >> time_begin >> time_end;
            int start = convertTime(time_begin);
            int endd = convertTime(time_end);
            pair<int, int> order_begin, order_en;
            order_begin.first = start;
            order_begin.second = 0;
            order_en.first = endd;
            order_en.second = INF;
            auto lo = lower_bound(prefix.begin(), prefix.end(), order_begin);
            if (lo != prefix.begin())
                lo--;
            auto hi = upper_bound(prefix.begin(), prefix.end(), order_en);
            if ((*hi).first != endd)
                hi--;
            cout << (*hi).second - (*lo).second << endl;
        }
    }
}
