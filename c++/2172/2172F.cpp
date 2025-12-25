#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define DEBUG false

using ll  = long long;
using ull = unsigned long long;

using ipair  = pair<int, int>;
using llpair = pair<ll, ll>;

using vi   = vector<int>;
using vb   = vector<bool>;
using vll  = vector<long long>;
using vull = vector<unsigned long long>;
using vstr = vector<string>;

#define bit(x,i) (x&(1LL<<i))

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

template<typename T>
vector<vector<T>> mtrx(size_t h, size_t l, T val = T()) {return vector<vector<T>>(h, vector<T>(l, val));}

void solve() {
  int n = inp();
  vi v(n);
  for(int& x : v) cin >> x;
  vi pref(n);
  vi suf(n);
  pref[0] = v[0];
  suf[n-1] = v[n-1];
  for(int i = 1; i < n; i++) {
    pref[i] = gcd(pref[i-1], v[i]);
  }
  for(int i = n - 2; i >= 0; i--) {
    suf[i] = gcd(suf[i+1], v[i]);
  }
  long long ans = suf[0];
  int p1 = 1;
  int p2 = n - 2;
  while(p2 >= p1) {
    if(pref[p2] < suf[p1]) {
      ans += pref[p2--];
    } else {
      ans += suf[p1++];
    }
  }
  cout << ans << "\n";
}

int main() {
  if(!DEBUG) {ios_base::sync_with_stdio(0); cin.tie(0);}
  solve();
}
/*

*/
