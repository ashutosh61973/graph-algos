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
int dfsum(int node, int exclude, vector<vector<int>> &graph, vector<int> &visited, vector<int> &Weight, int n)
{
    visited[node] = 1;
    int sum = Weight[node];
    for (auto x : graph[node])
    {
        if (x == exclude)
        {
            continue;
        }
        if (!visited[x])
            sum = sum + dfsum(x, exclude, graph, visited, Weight, n);
    }
    return sum;
}
void remove_edge(vector<vector<int>> &graph, vector<pair<int, int>> &edge, vector<int> &Weight, int n)
{
    int ans = 0;
    int sum = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + Weight[i];
        cout << Weight[i] << endl;
    }
    ans = sum;
    cout << sum << endl;
    for (auto x : edge)
    {
        vector<int> visited(n, 0);
        sum1 = dfsum(x.first, x.second, graph, visited, Weight, n);
        sum2 = sum - sum1;
        ans = min(ans, abs(sum2 - sum1));
    }

    //cout << ans << endl;
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
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> Weight(n);
    int summ = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Weight.push_back(x);
        summ += x;
    }
    // cout << summ << endl;
    vector<pair<int, int>> edge;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    remove_edge(graph, edge, Weight, n);
}
