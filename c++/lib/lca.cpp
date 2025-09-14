#include <bits/stdc++.h>
using namespace std;

#ifndef GRAPH_T
#define GRAPH_T
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
#endif

constexpr int MAX_DEPTH = 22;
struct lca_t {
  graph_t g; // needs to be a tree otherwise this will make it one in a dumb way
  int root;
  vector<array<int, MAX_DEPTH>> jump;
  vector<int> depths;

  lca_t(graph_t graph, int root) : g(graph), root(root), jump(g.n+1, array<int, MAX_DEPTH>{}), depths(g.n+1) {}
  array<int, MAX_DEPTH>& operator[](int i) { return jump[i]; }

  int lca(int a, int b) {
    if(depths[a] < depths[b]) swap(a, b);
    for(int i = 21; i >= 0; i--) if(depths[jump[a][i]] >= depths[b]) a = jump[a][i];
    for(int i = 21; i >= 0; i--) if(jump[a][i] != jump[b][i]) { a = jump[a][i]; b = jump[b][i]; }
    return jump[a][0];
  }
};

void lca_dfs(int node, graph_t& graph, lca_t& lca) {
  for(int x : graph[node]) {
    if(lca[x][0] == 0) {
      lca[x][0] = node;
      lca.depths[x] = lca.depths[node] + 1;
      lca_dfs(node, graph, lca);
    }
  }
}

lca_t lca(graph_t graph, int root) {
  lca_t res(graph, root);
  res[root][0] = root;
  res.depths[root] = 0;
  lca_dfs(root, graph, res);
  for(int i = 1; i < MAX_DEPTH; i++) {
    for(int v : graph.nodes()) {
      res[v][i] = res[res[v][i-1]][i-1];
    }
  }

  return res;
}
