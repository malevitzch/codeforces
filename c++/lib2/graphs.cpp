#include <vector>
#include <algorithm>

// A graph is represented by a list of n outgoing edge vector, numbered from 0 to n - 1
struct graph_t {
    const int vertex_count;
    int size() { return vertex_count; }
    std::vector<std::vector<int>> edges;
    std::vector<int>& out(int index) {
        return edges[index];
    }
    void add_edge(int from, int to) {
        edges[from].push_back(to);
    }
    void add_edge(std::pair<int, int> e) {
        edges[e.first].push_back(e.second);
    }
    graph_t(int n) : vertex_count(n), edges(std::vector<std::vector<int>>(n)) {}
    graph_t(int n, std::vector<std::pair<int, int>> edges) : vertex_count(n) {
        for(auto& e : edges) add_edge(e);
    }
};

void topo_dfs(graph_t& graph, std::vector<bool>& vis, std::vector<int>& res, int v) {
    vis[v] = true;
    for(int x : graph.out(v)) {
        if(!vis[x]) topo_dfs(graph, vis, res, x);
    }
    res.push_back(v);
}

std::vector<int> toposort(graph_t& graph) {
    std::vector<bool> vis(graph.size());
    std::vector<int> res;
    for(int i = 0; i < graph.size(); i+) {
        if(!vis[i]) topo_dfs(graph, vis, res, i);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

void reachable_dfs(graph_t& graph, std::vector<bool>& vis, int v) {
    vis[v] = true;
    for(int x : graph.out(v)) {
        if(!vis[x]) reachable_dfs(graph, vis, x);
    }
}
std::vector<bool> reachable(graph_t& graph, int start) {
    std::vector<bool> vis(graph.size());
    reachable_dfs(graph, vis, start);
    return vis;
}