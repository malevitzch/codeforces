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

struct graph_t {
  int n;
  vector<vector<int>> g;

  vector<int>& operator[](int i) { return g[i]; }
  graph_t(int size) : n(size), g(size+1) {}
  graph_t() = default;
  vector<int> nodes() {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    return v;
  }
};

void topo_dfs(int node, graph_t& graph, vector<bool>& vis, vector<int>& res) {
  vis[node] = true;
  for(int x : graph[node])
    if(!vis[x])
      topo_dfs(x, graph, vis, res);
  res.push_back(node);
}

// Assumes nodes are ordered from 1 to n
vector<int> toposort(graph_t& graph) {
  vector<int> result;
  vector<bool> vis(graph.n+1);
  for(int i : graph.nodes()) if(!vis[i]) topo_dfs(i, graph, vis, result);
  reverse(result.begin(), result.end());
  return result;
}

graph_t reverse_graph(graph_t& graph) {
  graph_t rev_graph(graph.n+1);
  for(int i : graph.nodes()) for(int x : graph[i]) rev_graph[x].push_back(i);
  return rev_graph;
}

struct scc_t {
  int n;
  vector<int> which;
  graph_t g;

  scc_t(int size) : n(size), which(size+1) {}
  int& operator[](int i) { return which[i]; }
};

void paint(int node, int color, graph_t& graph, vector<int>& colors) {
  colors[node] = color;
  for(int x : graph[node]) if(!colors[x]) paint(x, color, graph, colors);
}

scc_t scc(graph_t& graph) {
  vector<int> order = toposort(graph);
  graph_t rg = reverse_graph(graph);
  scc_t res(graph.n);
  int color = 0;
  for(int v : order) if(!res[v]) paint(v, ++color, rg, res.which);
  res.g = graph_t(color);
  for(int i : graph.nodes())
    for(int x : graph[i])
      if(res[i] != res[x])
        res.g[res[i]].push_back(res[x]);
  return res;
}

void find_leaves(int node, graph_t& g, vb& vis, vector<int>& res) {
  vis[node] = true;
  int c = 0;
  for(int x : g[node]) {
    if(!vis[x]) {
      c++;
      find_leaves(x, g, vis, res);
    }
  }
  if(c == 0) {
    res.push_back(node);
  }
}

void solve() {
  int n;
  cin >> n;
  graph_t graph(n);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    graph[i].push_back(x);
  }

  scc_t s = scc(graph);
  graph_t sccg = s.g;
  int k = sccg.n;
  if(k == 1) {
    cout << "0\n";
    return;
  }
  vector<int> rep(k+1);

  for(int i : graph.nodes()) {
    rep[s[i]] = i;
  }

  vi order = toposort(sccg);
  vector<ipair> res;
  vb vis(k+1);
  vector<pair<int, vi>> srcs;
  for(int i : sccg.nodes()) {
    if(!vis[i]) {
      srcs.push_back({i, {}});
      find_leaves(i, sccg, vis, srcs.back().second);
    }
  }
  for(int i = 0; i < srcs.size(); i++) {
    for(int x : srcs[i].second) {
      res.push_back({ x, srcs[(i+1) % srcs.size()].first });
    }
  }
  cout << res.size() << "\n";
  for(auto&[from, to] : res) {
    cout << rep[from] << " " << rep[to] << "\n";
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
