#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int to, cap, rev;
};

vector<vector<Edge>> graph;
vector<bool> visited;

int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    visited[v] = true;
    for (Edge &e : graph[v])
    {
        if (!visited[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t)
{
    int flow = 0;
    while (true)
    {
        visited.assign(graph.size(), false);
        int f = dfs(s, t, INF);
        if (f == 0)
            break;
        flow += f;
    }
    return flow;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int s, t;
    cin >> s >> t;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        // Explicitly provide the type for vector elements
        graph[u].push_back(Edge{v, c, static_cast<int>(graph[v].size())});
        graph[v].push_back(Edge{u, 0, static_cast<int>(graph[u].size()) - 1});
    }

    int maxFlowValue = maxFlow(s, t);

    cout << maxFlowValue << endl;

    return 0;
}
