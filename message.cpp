#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;
void message(vector<vector<int>> &graph, int n)
{
    vector<int> visited(n + 1, 0);
    queue<pair<int, int>> q;
    int flag = 0;
    q.push({1, 1}); //node,dis
    visited[1] = 1;
    int time = 0;
    vector<int> path(n + 1);
    path[1] = -1;
    while (!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        if (node == n)
        {
            flag = 1;
            time = d;
            break;
        }
        for (auto x : graph[node])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push({x, d + 1});
                path[x] = node;
            }
        }
    }
    if (flag)
    {
        cout << time << endl;
        stack<int> s;
        for (int node = n; node != -1; node = path[node])
        {
            s.push(node);
        }
        while (!s.empty())
        {
            cout << (s.top()) << " ";
            s.pop();
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, e;
    cin >> n;
    cin >> e;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    message(graph, n);
}
// https://cses.fi/paste/a30a50fc13e3ece818070a/