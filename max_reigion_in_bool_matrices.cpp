#include "bits/stdc++.h"

using namespace std;

int ans = 0;
int x_dir[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int y_dir[] = {0, 0, 1, -1, 1, 1, -1, -1};
bool is_safe(int i, int j, int n, int m, vector<vector<int>> &graph, vector<vector<int>> &visited)
{
    return i >= 0 and i < n and j >= 0 and j < m and graph[i][j] and !visited[i][j];
}
int find_max_region_util(int cnt, int i, int j, vector<vector<int>> &graph, vector<vector<int>> &visited, int n, int m)
{

    visited[i][j] = 1;
    int sum = 0;
    for (int k = 0; k < 8; k++)
    {

        if (is_safe(i + x_dir[k], j + y_dir[k], n, m, graph, visited))
        {
            sum = sum + 1 + find_max_region_util(cnt, i + x_dir[k], j + y_dir[k], graph, visited, n, m);
        }
    }
    return sum;
}
void find_max_region(vector<vector<int>> &graph, int n, int m)
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((!visited[i][j]) && graph[i][j])
            {
                ans = max(ans, 1 + find_max_region_util(0, i, j, graph, visited, n, m));
            }
        }
    }
    cout << ans << endl;
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

    int n;
    int m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                graph[i][j] = 1;
            }
        }
    }

    find_max_region(graph, n, m);
}
