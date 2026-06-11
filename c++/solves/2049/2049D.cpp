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

void solve() {
  ll n = inp();
  ll m = inp();
  ll f = inp();
  vector<vll> nums(n, vll(m));
  for(auto& v : nums)
    for(auto& x : v)
      cin >> x;

  vector<vector<vll>> dp(n, vector<vll>(m, vll(m, LLONG_MAX)));
  vector<vll> best(n, vll(m, LLONG_MAX));
  for(int i = 0; i < m; i++) {
    dp[0][0][i] = nums[0][i] + i * f;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < m; k++) {
        if(i > 0) {
          dp[i][j][k] = min(dp[i][j][k], best[i-1][j] + nums[i][(j + k) % m] + k * f);
        }
        if(j > 0) {
          // Without k * f since it's already accounted for
          dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k] + nums[i][(j + k) % m]);
        }
        best[i][j] = min(best[i][j], dp[i][j][k]);
      }
    }
  }
  cout << best[n-1][m-1] << "\n";
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
