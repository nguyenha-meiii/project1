#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 2000000000000000000LL;

struct Edge
{
    int v;
    long long w; // cạnh từ u đến v, trọng số w
};

void dijkstra(int n, int S, vector<vector<Edge>> &graph, vector<long long> &D, vector<int> &trace)
{
    // graph: danh sách cạnh
    // n: số đỉnh
    // S: đỉnh bắt đầu
    // D: độ dài đường đi ngắn nhất
    // trace: mảng truy vết đường đi
    // INF nếu không có đường đi
    // -INF nếu có đường đi âm vô tận
    D.resize(n, INF);
    trace.resize(n, -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    D[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;

        if (d > D[u])
        {
            continue;
        }

        for (auto E : graph[u])
        {
            int v = E.v;
            long long w = E.w;
            if (D[u] + w < D[v])
            {
                D[v] = D[u] + w;
                trace[v] = u;
                pq.push({D[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }

    vector<long long> D;
    vector<int> trace;
    for (int s = 0; s < n; s++)
    {
        vector<long long> D;
        vector<int> trace;
        dijkstra(n, s, graph, D, trace);

        for (int t = 0; t < n; t++)
        {
            if (D[t] != INF)
            {
                cout << D[t] << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
