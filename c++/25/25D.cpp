#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0

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

vector<int> rep;
vector<int> ranks;

int find(int x) {
  if(rep[x] != x) {
    rep[x] = find(rep[x]);
  }
  return rep[x];
}

bool unionize(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y)
    return false;
  if(ranks[x] > ranks[y]) {
    rep[y] = x;
  }
  else if(ranks[x] < ranks[y]) {
    rep[x] = y;
  }
  else {
    rep[x] = y;
    ranks[y]++;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  rep.resize(n+1);
  ranks.resize(n+1);
  iota(rep.begin(), rep.end(), 0);
  vector<pair<int, int>> edges;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
  }
  vector<pair<int, int>> spares;
  for(auto&[a, b] : edges) {
    if(!unionize(a, b)) {
      spares.push_back({a, b});
    }
  }
  set<int> uniq;
  for(int i = 1; i <= n; i++) {
    uniq.insert(find(rep[i]));
  }
  vi v(uniq.begin(), uniq.end());
  cout << v.size() - 1 << "\n";
  for(int i = 0; i < uniq.size() - 1; i++) {
    cout << spares[i].first << " " << spares[i].second;
    cout << " " << v[i] << " " << v[i+1] << "\n";
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
