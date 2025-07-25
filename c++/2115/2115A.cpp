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

vector<vector<int>> gcds(5001, vector<int>(5001, -1));

int getGcd(int a, int b) {
  if(b == 0) {
    gcds[a][b] = a;
  }
  if(gcds[a][b] == -1)
    gcds[a][b] = getGcd(b, a % b);
  return gcds[a][b];
}

void solve() {
  int n = inp();
  vi v(n);
  for(auto& x : v) inp(x);
  int g = v[0];
  for(auto& x : v)
    g = getGcd(g, x);
  ll ans = 0;
  for(int x : v) 
    ans += (x != g);
  if(ans != n) {
    cout << ans << "\n";
    return;
  }
  vi dp(5001, n);
  dp[g] = 0;
  for(int x : v) {
    for(int i = 1; i <= 5000; i++) {
      int d = getGcd(x, i);
      if(dp[d] < n) {
        dp[i] = min(dp[i], dp[d] + 1);
      }
    }
  }
  ans = INT_MAX;
  for(int x : v) {
    ans = min(ans, (ll)dp[x]);
  }
  cout << ans + n - 1 << "\n";
}

int main() {
  if(!DEBUG) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  //preprocess();
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}
/*

*/
