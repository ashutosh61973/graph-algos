#include "bits/stdc++.h"

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool is_inside(int n, int sx, int sy)
{
    return sx <= n and sy <= n and sx >= 1 and sy >= 1;
}
int minpathbfs(int sx, int sy, int tx, int ty, int n, vector<vector<int>> &graph, vector<vector<int>> &visi)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(sx, sy), 0));
    visi[sx][sy] = 1;
    while (!q.empty())
    {
        auto val = q.front();
        q.pop();
        if (val.first.first == tx && val.first.second == ty)
        {
            return val.second;
        }
        for (int k = 0; k < 4; k++)
        {
            int nextx, nexty;
            nextx = val.first.first + dx[k];
            nexty = val.first.second + dy[k];
            int lev = val.second;
            if (is_inside(n, nextx, nexty) and (visi[nextx][nexty] == 0) and graph[nextx][nexty] != 0)
            {
                visi[nextx][nexty] = 1;
                q.push({{nextx, nexty}, lev + 1});
            }
        }
    }
    return -1;
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
    /*
A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
*/
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    int sx, sy;
    int tx, ty;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
            {
                sx = i;
                sy = j;
            }
            if (graph[i][j] == 2)
            {
                tx = i;
                ty = j;
            }
        }
    }
    vector<vector<int>> visi(n + 1, vector<int>(n + 1, 0));
    cout << minpathbfs(sx, sy, tx, ty, n, graph, visi) << endl;
}
