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

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

struct chk {
  int s, t, w;
};

void solve() {
  int n = inp();
  int m = inp();
  vll b(n);
  for_each(b.begin(), b.end(), [](ll& x){inp(x);});
  vector<chk> ch(m);
  for(chk& x : ch) {
    cin >> x.s >> x.t >> x.w;
  }
  vector<vector<ipair>> graph(n);
  for(chk c : ch) {
    graph[c.s - 1].push_back({c.t - 1, c.w});
  }

  ll l = 1;
  ll r = 1e9 + 42;
  while(l < r) {
    ll mid = (l + r) / 2;
    bool possible = false;
    vll dp(n, -1);
    dp[0] = 0;
    for(int i = 0; i < n - 1; i++) {
      if(dp[i] == -1) continue;
      dp[i] = min(dp[i] + b[i], mid);
      for(auto&[target, cost] : graph[i]) {
        if(cost <= dp[i]) {
          dp[target] = max(dp[target], dp[i]);
        }
      }
    }

    if(dp.back() != -1) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if(l == 1e9 + 42) cout << "-1\n"; else cout << l << "\n";

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
