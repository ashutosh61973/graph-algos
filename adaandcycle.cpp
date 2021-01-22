#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

int bfs(int node, vector<vector<int>> &graph, int n)
{
    queue<pair<int, int>> q;
    vector<int> visited(n + 1, 0);
    q.push({node, 0});
    visited[node] = 1;
    while (!q.empty())
    {
        int root = q.front().first;
        int d = q.front().second;
        q.pop();
        for (auto x : graph[root])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push({x, d + 1});
            }
            else
            {
                if (x == node)
                {
                    return d + 1;
                }
            }
        }
    }
    return -1;
}
void adaandcycle(vector<vector<int>> &graph, int n)
{
    for (int node = 1; node <= n; node++)
    {
        int val = bfs(node, graph, n);
        if (val == -1)
        {
            cout << "NO WAY" << endl;
        }
        else
        {
            cout << val << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    adaandcycle(graph, n);
}
