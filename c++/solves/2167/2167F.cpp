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

vi knodes;
vi cnt;

vector<vi> graph;

int n, k;

void calc(int node) {
  cnt[node] = 1;
  knodes[node] = 0;
  for(int x : graph[node]) {
    if(cnt[x] != -1) continue;
    calc(x);
    cnt[node] += cnt[x];
    knodes[node] += knodes[x];
  }
  if(cnt[node] >= k) {
    knodes[node]++;
  }
}

ll ans;
vector<bool> vis;

void reroot(int node, int parent) {
    if(cnt[parent] >= k && cnt[parent] - cnt[node] < k) knodes[parent]--;
    cnt[parent] -= cnt[node];
    knodes[parent] -= knodes[node];

    knodes[node] += knodes[parent];
    if(cnt[node] < k && cnt[node] + cnt[parent] >= k) knodes[node]++;
    cnt[node] += cnt[parent];
}

void answer(int node, int parent) {
  vis[node] = true;
  if(parent != -1) {
    reroot(node, parent);
  }
  ans += knodes[node];
  for(int x : graph[node]) {
    if(vis[x]) continue;
    answer(x, node);
  }
  if(parent != -1) {
    reroot(parent, node);
  }

}

void solve() {
  cin >> n >> k;
  knodes = vi(n + 1, -1);
  cnt = vi(n + 1, -1);
  graph = vector<vi>(n + 1);
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  ans = 0;
  vis = vector<bool>(n + 1);
  calc(1);
  answer(1, -1);
  cout << ans << "\n";

}

int main() {
  if(!DEBUG) {ios_base::sync_with_stdio(0); cin.tie(0);}
  int t = inp();
  while(t--) solve();
}
/*

*/
