#include "bits/stdc++.h"

using namespace std;

struct point
{
    int x, y;
    point()
    {
    }
    point(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
};
bool is_inside(point child, int n)
{
    int x = child.x;
    int y = child.y;
    return x <= n and x >= 1 and y >= 1 and y <= n;
}
int min_path(point source, point target, vector<vector<int>> &graph, int n)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    pair<point, int> s;
    /* s.first.x = source.x;
    s.first.y = source.y;*/
    s.first = point(source.x, source.y);
    s.second = 0;
    queue<pair<point, int>> q;
    q.push(s);
    graph[s.first.x][s.first.y] = 1;
    while (!q.empty())
    {
        pair<point, int> val = q.front();
        q.pop();
        if ((val.first.x == target.x) && (val.first.y == target.y))
        {
            return val.second;
        }
        for (int k = 0; k < 8; k++)
        {
            point child;
            /* child.x = val.first.x + dx[k];
            child.y = val.first.y + dy[k];*/
            child = point(val.first.x + dx[k], val.first.y + dy[k]);
            if ((is_inside(child, n)) && (graph[child.x][child.y] == -1))
            {
                graph[child.x][child.y] = 1;
                q.push(make_pair(child, val.second + 1));
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

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
    point source, target;
    cin >> source.x >> source.y;
    cin >> target.x >> target.y;
    cout << min_path(source, target, graph, n);
}
