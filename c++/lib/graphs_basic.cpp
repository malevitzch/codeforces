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

void topo_dfs(int node, graph_t& graph, vector<bool>& vis, vector<int>& res) {
  vis[node] = true;
  for(int x : graph[node]) if(!vis[x]) topo_dfs(x, graph, vis, res);
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

  scc_t(int size) : n(size+1), which(n+1) {}
  int& operator[](int i) { return which[i]; }
  int count() { return g.n; }
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
