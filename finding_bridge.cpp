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
void display(vector<vector<int>> &ans)
{
    for (auto x : ans)
    {
        cout << x[0] << " " << x[1] << endl;
    }
}
bool comp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
    {
        return true;
    }
    if (a[0] == b[0])
    {
        if (a[1] < b[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
int tim = 0;
void dfs(int node, int p, vector<vector<int>> &graph, int n, vector<int> &vis, vector<vector<int>> &ans, vector<int> &in, vector<int> &low)
{
    vis[node] = 1;
    in[node] = tim;
    low[node] = tim;
    tim++;
    for (auto child : graph[node])
    {
        if (child == p)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node, graph, n, vis, ans, in, low);
            low[node] = min(low[node], low[child]);
            if (low[child] > in[node])
            {
                vector<int> temp(2);
                if (child < node)
                {
                    temp[0] = child;
                    temp[1] = node;
                }
                else
                {
                    temp[0] = node;
                    temp[1] = child;
                }
                ans.push_back(temp);
            }
        }
    }
    return;
}
void solve(vector<vector<int>> &graph, int n)
{
    vector<vector<int>> ans;
    vector<int> vis;
    vis.assign(n + 1, false);
    vector<int> in(n + 1, -1), low(n + 1, -1);
    dfs(1, -1, graph, n, vis, ans, in, low);
    sort(ans.begin(), ans.end(), comp);
    if (ans.size() > 0)
    {
        cout << ans.size() << endl;
        display(ans);
    }
    else
    {
        cout << "Sin bloqueos" << endl;
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
    //graph finding algorithm
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int n, e;
        cin >> n;
        cin >> e;

        vector<vector<int>> graph(n + 1);
        // vector<vector<int>> ans;
        for (int i = 1; i <= e; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            //vector<int> temp(2);
            //if (u > v)
            //{
            //   swap(u, v);
            // }
            // temp[0] = u;
            //temp[1] = v;
            //ans.push_back(temp);
        }
        /*if (e == (n - 1))
        {
            cout << "Caso #" << c << endl;
            cout << ans.size() << endl;
            sort(ans.begin(), ans.end(), comp);
            display(ans);
            c++;
        }*/

        cout << "Caso #" << c << endl;
        solve(graph, n);
        c++;

        tim = 0;
    }
}
