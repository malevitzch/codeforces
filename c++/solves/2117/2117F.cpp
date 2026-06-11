#include <bits/stdc++.h>
using namespace std;

#define DEBUG false

#define ll long long
#define ull unsigned long long

#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vstr vector<string>

#define bit(x,i) (x&(1<<i))

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG

long long p = 1e9 + 7;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> depths;
vector<int> ch;
int findChildNodes(int v, int depth) {
  depths[v] = depth;
  int res = 0;
  vis[v] = true;
  int direct = 0;
  for(int& x : graph[v]) {
    if(!vis[x]) {
      res += findChildNodes(x, depth + 1);
    }
  }
  if(res == 0) {
    ch.push_back(v);
  }
  return max(res, 1);
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> edges;
  graph.clear();
  graph.resize(n+1);
  vis.clear();
  vis.resize(n+1);
  ch.clear();
  depths.clear();
  depths.resize(n+1);
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    edges.push_back({a, b});
  }
  int children = findChildNodes(1, 0);
  if(children > 2) {
    cout << 0 << "\n";
    return;
  }
  if(children == 1) {
    long long ans = 1;
    for(int i = 0; i < n; i++) {
      ans = (ans * 2) % p;
    }
    cout << ans << "\n";
    return;
  }

  int neck = 0;
  if(graph[1].size() == 1) {
    int prev = 1;
    int cur = graph[1][0];
    neck++;
    while(1) {
      if(graph[cur].size() > 2) {
        break;
      }
      neck++;
      if(graph[cur][0] == prev) {
        prev = cur;
        cur = graph[cur][1];
      } else {
        prev = cur;
        cur = graph[cur][0];
      }
    }
  }

  int d1 = depths[ch[0]];
  int d2 = depths[ch[1]];
  if(d1 > d2) swap(d1, d2);
  long long ans = 2;

  long long a1 = 1;
  for(int i = 0; i < d2 - d1; i++) {
    a1 = (a1 * 2) % p;
  }

  long long a2 = 1;
  for(int i = 1; i < d2 - d1; i++) {
    a2 = (a2 * 2) % p;
  }

  ans = (ans * (a1 + a2)) % p;
  while(neck > 0) {
    ans = (ans * 2) % p;
    neck--;
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
