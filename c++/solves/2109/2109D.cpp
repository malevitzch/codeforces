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

struct el {
  int target;
  int value;
  bool which;
};

void solve() {
  int n = inp();
  int m = inp();
  int l = inp();
  vi a(l);
  for(auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<vi> graph(n+1);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vll dp[2]; // even and odd
  dp[0].resize(n+1, INT_MIN);
  dp[1].resize(n+1, INT_MIN);
  dp[1][0] = 0;
  queue<el> q;
  q.push({1, 0, 0});
  while(!q.empty()) {
    auto[target, value, which] = q.front();
    q.pop();
    if(dp[which][target] == INT_MIN) {
      dp[which][target] = value;
      for(int x : graph[target]) {
        q.push({x, value + 1, !which});
      }
    }
  }
  ll sum = 0;
  ll even = -1;
  ll odd = -1;
  for(int x : a) sum += x;
  if(sum % 2 == 0) {
    even = sum;
    odd = sum;
    for(int x : a) {
      if(x % 2 == 1) {
        odd -= x;
        break;
      }
    }
    if(odd == even) odd = -1;
  } else {
    odd = sum;
    even = sum;
    for(int x : a) {
      if(x % 2 == 1) {
        even -= x;
        break;
      }
    }
    if(odd == even) even = -1;
  }
  string ans;
  for(int i = 1; i <= n; i++) {
    int a = dp[0][i];
    int b = dp[1][i];
    bool possible = false;
    if(a != INT_MIN) {
      if(even >= a) {
        possible = true;
      }
    }
    if(b != INT_MIN) {
      if(odd >= b) {
        possible = true;
      }
    }
    ans += possible ? "1" : "0";
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
