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

}

int main() {
  if(!DEBUG) {ios_base::sync_with_stdio(0); cin.tie(0);}
  int t = inp();
  while(t--) solve();
}
/*

*/
