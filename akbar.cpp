#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

void multisourcesbfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &protect, vector<pair<int, int>> &nodes_in_muti_bfs, int n)
{
    queue<pair<int, int>> q;
    for (auto x : nodes_in_muti_bfs)
    {
        q.push(x);
        visited[x.first] = 1;
    }
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int node = t.first;
        int st = t.second;
        for (auto x : graph[node])
        {
            if ((st >= 1) and !visited[x])
            {
                visited[x] = 1;
                q.push({x, st - 1});
                protect[x] = 1;
            }
        }
    }
}
void optimum(vector<vector<int>> &graph, int n, vector<int> &strength)
{
    vector<pair<int, int>> nodes_in_muti_bfs;
    vector<int> protect(n + 1, 0);
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (strength[i] != -1)
        {
            nodes_in_muti_bfs.push_back({i, strength[i]});
            protect[i] = 1;
        }
    }
    multisourcesbfs(graph, visited, protect, nodes_in_muti_bfs, n);
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (protect[i] == 0)
        {
            f = 0;
            break;
        }
    }
    if (f == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    int t;
    cin >> t;
    while (t--)
    {
        int n, r, m;
        cin >> n >> r >> m;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < r; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> strength(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
            int node, s;
            cin >> node >> s;
            strength[node] = s;
        }
        optimum(graph, n, strength);
    }
}
