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

int min_convert_step(int x, int y)
{
    queue<pair<int, int>> q; //pair<node,distance>
    unordered_set<int> s;
    q.push(make_pair(x, 0));
    s.insert(x);
    while (!q.empty())
    {
        auto val = q.front();
        q.pop();
        int num = val.first;
        int level = val.second;
        if (num == y)
        {
            return level;
        }
        if (num == 0)
        {
            continue;
        }
        int num1, num2;
        num1 = num - 1;
        num2 = num * 2;
        if (s.find(num1) == s.end())
        {
            q.push(make_pair(num1, level + 1));
        }
        if (s.find(num2) == s.end())
        {
            q.push(make_pair(num2, level + 1));
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
    int x;
    int y;
    cin >> x;
    cin >> y;
    int res = min_convert_step(x, y);
    if (res != -1)
    {
        cout << res << endl;
    }
}
