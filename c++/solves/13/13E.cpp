#include <bits/stdc++.h>
using namespace std;

#define DEBUG false

#define ll long long
#define ull unsigned long long

#define ipair pair<int, int>
#define llpair pair<ll, ll>

#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vstr vector<string>

#define bit(x,i) (x&(1<<i))

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

const int BLOCK_SIZE = 317;
int get_block(int k) {
  return k / 317;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vi holes(n+1);
  for(int i = 1; i <= n; i++) {
    cin >> holes[i];
  }

  vi jumps(n+1);
  vi lasthole(n+1);
  for(int i = n; i > 0; i--) {
    if(i + holes[i] > n || get_block(i + holes[i]) != get_block(i)) {
      jumps[i] = 1;
      lasthole[i] = i;
    } else {
      jumps[i] = jumps[i + holes[i]] + 1;
      lasthole[i] = lasthole[i + holes[i]];
    } 
  }

  for(int k = 0; k < m; k++) {
    int t;
    cin >> t;
    if(t == 0) {
      int a, b;
      cin >> a >> b;
      holes[a] = b;
      for(int i = a; i >= get_block(a) * BLOCK_SIZE; i--) {
        if(i + holes[i] > n || get_block(i + holes[i]) != get_block(i)) {
          jumps[i] = 1;
          lasthole[i] = i;
        } else {
          jumps[i] = jumps[i + holes[i]] + 1;
          lasthole[i] = lasthole[i + holes[i]];
        } 
      }
    } else {
      int x;
      cin >> x;
      int ans = 0;
      int last = x;
      while(x <= n) {
        ans += jumps[x];
        x = lasthole[x];
        last = x;
        x += holes[x];
      }
      cout << last << " " << ans << "\n";
    }
  }

}

int main() {
  if(!DEBUG) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  solve();
}
/*

*/
