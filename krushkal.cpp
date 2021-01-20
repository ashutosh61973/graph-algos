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
vector<int> Rank(100005);
int find(int x, vector<int> &parent)
{
  if (x == parent[x])
  {
    return x;
  }
  return parent[x] = find(parent[x], parent);
}
void Union(int u, int v, int w, vector<int> &parent, int &sum)
{
  u = find(u, parent);
  v = find(v, parent);
  if (u != v)
  {
    cout << w << "+";
    if (Rank[v] > Rank[u])
    {
      swap(u, v);
    }
    parent[v] = u;
    if (Rank[u] == Rank[v])
      Rank[u]++;
    sum += w;
  }
  return;
}

/*///////////////////////**O(MLOGN +N^2)**/ /////////////////////////////////////*/
struct edge
{
  int w;
  int u;
  int v;
};
bool cmp(const edge &a, const edge &b)
{
  return a.w <= b.w; //for maximum spannin tree compare like this -->a.w>=b.w
}
typedef struct edge edge;
/*/////////////////////////////////////////////////////////*/

void solve_krushkal(vector<edge> &q, int n)
{
  vector<int> parent(n + 1);
  Rank.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    Rank[i] = 0;
  }
  int sum = 0;
  for (auto x : q)
  {
    Union(x.u, x.v, x.w, parent, sum);
  }
  cout << "->";
  cout << "totalsum"
       << "->";
  cout << sum << endl;
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
  //vector<vector<pair<int,int>>>graph(n);
  vector<edge> q;
  while (1)
  {

    int u;
    cin >> u;
    if (u == -1)
    {
      break;
    }
    int v, w;
    cin >> v >> w;
    edge e;
    e.u = u;
    e.v = v;
    e.w = w;
    q.push_back(e);
  }

  sort(q.begin(), q.end(), cmp);

  /*for (auto x : q)
  {
    cout << x.u << " " << x.v << " " << x.w << endl;
  }*/
  solve_krushkal(q, n);
}
