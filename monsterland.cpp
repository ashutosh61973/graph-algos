#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool check(int x, int y, vector<vector<char>> &graph, vector<vector<int>> &visi, int n, int m)
{
    return x < n and x >= 0 and y < m and y >= 0 and graph[x][y] != 'M' and graph[x][y] != '#' and visi[x][y] == 0;
}
void multisourcesbfs(vector<vector<char>> &graph, int n, int m, vector<int> &monstime, vector<pair<int, int>> &monsnode)
{
    queue<pair<int, int>> q;
    vector<vector<int>> visi(n, vector<int>(m, 0));
    for (auto xy : monsnode)
    {
        q.push({xy.first, xy.second});
        int nodi = (m * (xy.first)) + xy.second;
        monstime[nodi] = 0;
        visi[xy.first][xy.second] = 1;
    }

    while (!q.empty())
    {
        //cout << i++ << endl;
        //auto t = q.front();
        //q.pop();
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nodi = m * (x) + y;
        if (check(x, y + 1, graph, visi, n, m))
        {
            visi[x][y + 1] = 1;
            monstime[m * (x) + y + 1] = monstime[nodi] + 1;
            q.push({x, y + 1});
        }
        if (check(x, y - 1, graph, visi, n, m))
        {
            visi[x][y - 1] = 1;
            monstime[m * (x) + y - 1] = monstime[nodi] + 1;
            q.push({x, y - 1});
        }
        if (check(x + 1, y, graph, visi, n, m))
        {
            visi[x + 1][y] = 1;
            monstime[m * (x + 1) + y] = monstime[nodi] + 1;
            q.push({x + 1, y});
        }
        if (check(x - 1, y, graph, visi, n, m))
        {
            visi[x - 1][y] = 1;
            monstime[m * (x - 1) + y] = monstime[nodi] + 1;
            q.push({x - 1, y});
        }
    }
}
void monster(int idx, int jdx, vector<vector<char>> &graph, int m, int n)
{

    vector<int> monstime(n * m, n * m + n);
    vector<pair<int, int>> monsnode;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'M')
            {
                monsnode.push_back({i, j});
            }
        }
    }
    multisourcesbfs(graph, n, m, monstime, monsnode);

    queue<pair<int, int>> q;
    vector<vector<int>> visi(n, vector<int>(m, 0));
    q.push({idx, jdx});
    visi[idx][jdx] = 1;
    vector<pair<int, char>> path(n * m); //node , turn
    int flag = 0;
    path[((idx)*m) + (jdx)] = {-1, 'S'};
    int lastx, lasty;
    vector<int> perstime(n * m, 0);

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        if ((y == m - 1 or x == 0 or y == 0 or x == n - 1))
        {
            flag = 1;

            lastx = x;
            lasty = y;
            break;
            //display();
        }
        if ((check(x, y + 1, graph, visi, n, m)) and ((perstime[m * (x) + y] + 1) <= monstime[m * (x) + y]))
        {
            visi[x][y + 1] = 1;
            q.push({x, y + 1});
            perstime[m * (x) + (y + 1)] = perstime[m * (x) + y] + 1;
            path[m * (x - 1) + (y + 1)] = {m * (x - 1) + y - 1, 'R'};
        }
        if (check(x, y - 1, graph, visi, n, m) and ((perstime[m * (x) + y] + 1) <= monstime[m * (x) + y]))
        {
            visi[x][y - 1] = 1;
            q.push({x, y - 1});
            perstime[m * (x) + (y - 1)] = perstime[m * (x) + y] + 1;
            path[m * (x) + (y - 1)] = {m * (x) + y, 'L'};
        }
        if (check(x + 1, y, graph, visi, n, m) and ((perstime[m * (x) + y] + 1) <= monstime[m * (x) + y]))
        {
            visi[x + 1][y] = 1;
            q.push({x + 1, y});
            perstime[m * (x + 1) + (y)] = perstime[m * (x) + y] + 1;
            path[m * (x + 1) + (y)] = {m * (x) + y, 'D'};
        }
        if (check(x - 1, y, graph, visi, n, m) and ((perstime[m * (x) + y] + 1) <= monstime[m * (x) + y]))
        {
            visi[x - 1][y] = 1;
            q.push({x - 1, y});
            perstime[m * (x - 1) + (y)] = perstime[m * (x) + y] + 1;
            path[m * (x - 1) + (y)] = {m * (x) + y, 'U'};
        }
    }
    //cout << flag << endl;
    if (flag == 1)
    {
        // cout << "lastx=>" << lastx << "==lasty" << lasty << endl;
        cout << "YES" << endl;
        int node = m * (lastx) + lasty;
        stack<char> s;
        for (int u = node; u != -1; u = path[u].first)
        {
            // cout << "as";
            if (path[u].first == -1)
            {
                continue;
            }
            s.push(path[u].second);
        }
        cout << s.size() << endl;
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
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
    int n, m;
    cin >> n >> m;
    int idx = 0, jdx = 0;
    vector<vector<char>> graph(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                idx = i;
                jdx = j;
            }
        }
    }
    monster(idx, jdx, graph, m, n);
}
