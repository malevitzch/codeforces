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


void getAns(int v, int p, int& ans, vi& dp, vector<vi>& graph) {
  int m1 = 0;
  int m2 = 0;
  for(int x : graph[v]) {
    if(x == p) continue;
    getAns(x, v, ans, dp, graph);
    if(dp[x] > m1) {
      m2 = m1;
      m1 = dp[x];
    } else if(dp[x] > m2) {
      m2 = dp[x];
    }
  }

  dp[v] = graph[v].size() - 1;
  dp[v] = max(dp[v], (int)graph[v].size() - 2 + m1);


  ans = max(ans, (int)graph[v].size() - 2 + m1 + m2);
  ans = max(ans, (int)graph[v].size() - 1 + m1);
  ans = max(ans, dp[v]);

  ans = max(ans, (int)graph[v].size());
}

void solve() {
  int n = inp();
  vector<vi> graph(n+1);
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vi dp(n+1, 0);
  int ans = 0;
  getAns(1, -1, ans, dp, graph);
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
