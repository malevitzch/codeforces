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

void solve() {
  map<int, vector<int>> graph;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  map<int, bool> vis;
  int start = 0;
  for(auto&[node, v] : graph) {
    if(v.size() == 1) start = node;
  }
  cout << start << " ";
  int prev = start;
  int cur = graph[start][0];
  while(graph[cur].size() != 1) {
    if(graph[cur][0] == prev) {
      prev = cur;
      cout << cur << " ";
      cur = graph[cur][1];
    } else {
      prev = cur;
      cout << cur << " ";
      cur = graph[cur][0];
    }
  }
  cout << cur << "\n";
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
