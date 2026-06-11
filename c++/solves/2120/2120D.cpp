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

inline void YES() {cout << "YES\n";}
inline void NO() {cout << "NO\n";}
inline void answer(bool b) {b ? YES() : NO();}
inline ll inp() {ll x; cin >> x; return x;}
inline ll& inp(ll& x) {cin >> x; return x;}
inline int& inp(int& x) {cin >> x; return x;}

const ll p = 1e9 + 7;

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

void solve() {
  ll a, b, k;
  cin >> a >> b >> k;
  ll n = ((a - 1) * k + 1) % p;

  ll m = (((k*(b - 1)) % p ) * inverse(factorial(a))) % p;
  for(ll i = 0; i < a; i++) {
    m = (m * ( (n - i + p) % p ) ) % p;
  }
  m = (m + 1) % p;
  cout << n << " " << m << "\n";
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
