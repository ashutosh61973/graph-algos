#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  int n=100000;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
        // Print all prime numbers 
           // for (int p=2; p<=n; p++) 
        // if (prime[p]) 
         // cout << p << " "; 
} 
*/
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////NCR////////////////////////////////////////
/*const int N=5000;
 
#define NCR
#define PRIME	M
inti pw(inti a,inti p=M-2,inti MOD=M){
    inti result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return result;
}
inti fact[N],invfact[N];
void init(){
    inti p=PRIME;
    fact[0]=1;
    inti i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
inti ncr(inti n,inti r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}*/
///////////////////////////////////////////////////////////////////////////////

////\\//////\\/////////\\///////////\\\////////\\/////////////\\\/////
/*
ll power(ll a, ll b) //time complexity is  o(log(b));
{
  if (a == 0)
    return 0;
  ll ans = 1;
  a = a % mod;
  while (b > 0)
  {
    if ((b & 1) == 1)
      ans = (ans * a) % mod;
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}*/
//\\////\\//////\\//////\//////\\///////\\//////////\\/////\\///
/*bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
 
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}*/
//////////////\\\\\\\\////////\\\\\\\\\\//////////\\\\////

///////////////////////////////////////////////////////////////////////

/*
//sort string by there length ==>

sort(v.begin(), v.end(), [&] (const string &s, const string &t) {
        return s.size() < t.size();
    });
*/

///////////////////////////////////////////////////////////////////////
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int givnode(int x, int y, int m)
{
    return ((m * (x)) + y);
}
bool check(int x, int y, vector<vector<char>> &graph, vector<vector<int>> &vis, int n, int m)
{
    return x < n and x >= 0 and y < m and y >= 0 and vis[x][y] == 0 and graph[x][y] != '#';
}
void path_exist(vector<vector<char>> &graph, pair<int, int> start, pair<int, int> en, int n, int m)
{
    vector<pair<int, char>> path((n * m) + 5);
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[start.first][start.second] = 1;
    path[givnode(start.first, start.second, m)] = {-1, 'S'};
    int flag = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        if (x == en.first and y == en.second)
        {
            flag = 1;
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            if (check(x + dx[k], y + dy[k], graph, vis, n, m))
            {
                vis[x + dx[k]][y + dy[k]] = 1;
                q.push({x + dx[k], y + dy[k]});
                if (dx[k] == -1 and dy[k] == 0)
                    path[givnode(x + dx[k], y + dy[k], m)] = {givnode(x, y, m), 'U'};
                if (dx[k] == 1 and dy[k] == 0)
                    path[givnode(x + dx[k], y + dy[k], m)] = {givnode(x, y, m), 'D'};
                if (dx[k] == 0 and dy[k] == 1)
                    path[givnode(x + dx[k], y + dy[k], m)] = {givnode(x, y, m), 'R'};
                if (dx[k] == 0 and dy[k] == -1)
                    path[givnode(x + dx[k], y + dy[k], m)] = {givnode(x, y, m), 'L'};
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        stack<char> s;
        int node = givnode(en.first, en.second, m);
        for (int u = node; u != -1; u = path[u].first)
        {
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
    if (flag == 0)
    {
        cout << "NO" << endl;
    }
}
int main()
{

    int n;
    int m;
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                start = {i, j};
            }
            if (graph[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
    path_exist(graph, start, end, n, m);
}
