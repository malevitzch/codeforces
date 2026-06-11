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

void direct(int node, bool parity, vector<ipair>& ans, vector<bool>& vis, vector<vector<int>>& graph) {
  vis[node] = true;
  for(int x : graph[node]) {
    if(vis[x]) continue;

    if(parity) {
      ans.push_back({x, node});
    } else {
      ans.push_back({node, x});
    }

    direct(x, !parity, ans, vis, graph);
  }
}

void solve() {
  int n = inp();
  vector<bool> vis(n+1);
  vector<vector<int>> graph(n+1);
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<ipair> ans;
  int v = 1;
  while(v <= n && graph[v].size() != 2) v++;
  if(v > n) {
    NO();
    return;
  }

  int v1 = graph[v][0];
  int v2 = graph[v][1];

  ans.push_back({v1, v});
  ans.push_back({v, v2});

  vis[v] = true;
  direct(v1, false, ans, vis, graph);
  direct(v2, true, ans, vis, graph);

  YES();
  for(auto&[a, b] : ans) cout << a << " " << b << "\n";
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
