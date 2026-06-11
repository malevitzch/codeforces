#include <bits/stdc++.h>
using namespace std;

#define DEBUG false

#define ll long long
#define ull unsigned long long

#define ipair pair<int, int>
#define llpair pair<ll, ll>

#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vstr vector<string>

#define bit(x,i) (x&(1<<i))

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG

long long p = 998244353;

long long factorial(int n) {
  static vector<long long> values = {1};
  while(n >= values.size()) {
    values.push_back((values.back() * values.size()) % p);
  }
  return values[n];
}

long long fastExpo(long long x, long long y) {
  if(y == 0) return 1;
  if(y % 2) return ((x % p) * fastExpo((x % p) * (x % p), y/2)) % p;
  return fastExpo(( (x % p) * (x % p) ) % p, y/2);
}

long long inverse(long long x) {
  return fastExpo(x, p - 2);
}

long long binom(long long n, long long k) {
  if(k == 0 || k == n) {
    return 1;
  }
  return (((factorial(n) * inverse(factorial(k))) % p) * inverse(factorial(n - k))) % p;
}

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

void solve() {
  vll c(26);
  for(ll& x : c) cin >> x;
  ll s = 0;
  for(ll& x : c) s += x;
  ll odd = s / 2;
  ll even = (s + 1) / 2;
  vector<ll> dp(odd + 1, 0);
  dp[0] = 1;
  for(ll x : c) {
    if(x == 0) continue;
    for(int i = odd; i >= x; i--) {
      dp[i] = (dp[i] + dp[i-x]) % p;
    }
  }

  ll ans = (factorial(odd) * factorial(even)) % p;

  ans = (ans * dp.back()) % p;
  for(ll x : c) {
    if(x != 0) ans = (ans * inverse(factorial(x))) % p;
  }

  cout << ans << "\n";
}

int main() {
  if(!DEBUG) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}
/*

*/
