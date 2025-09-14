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

int n, m;

void paint(int color, int x, int y, vstr& graph, vector<vi>& colors, vi& counts) {
  colors[x][y] = color;
  for(auto&[a, b] : vector<ipair>{{x + 1, y}, {x - 1, y}, {x, y - 1}, {x, y + 1}}) {
    if(a < 0 || a >= n || b < 0 || b >= m) continue;
    if(colors[a][b] != 0) continue;
    if(graph[a][b] == '*') counts.back()++; else paint(color, a, b, graph, colors, counts);
  }
}

void solve() {
  int k;
  cin >> n >> m >> k;
  vstr graph(n);
  for(auto& x : graph) cin >> x;
  vector<vi> colors(n, vi(m, 0));
  vector<int> counts;
  int color = 1;
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if(colors[x][y] != 0) {
      cout << counts[colors[x][y]-1] << "\n";
    } else {
      counts.push_back(0);
      paint(color++, x, y, graph, colors, counts);
      cout << counts[colors[x][y]-1] << "\n";
    }
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
