#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve()
{

}

int main()
{
  if(!DEBUG)
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t;
  cin>>t;
  while(t--)
  {
    string a, b, c;
    cin>>a>>b>>c;
    int n = a.size();
    int m = b.size();
    int k = m + n;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++) {
      dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
    }
    for(int i = 1; i <= m; i++) {
      dp[0][i] = dp[0][i-1] + (b[i-1] != c[i-1]);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        dp[i][j] = min(dp[i-1][j] + (a[i-1] != c[i+j-1]), dp[i][j-1] + (b[j-1] != c[i+j-1]));
        if(i + j == k) ans = min(ans, dp[i][j]);
        if(i + j > k) continue;
      }
    }
    cout << ans << "\n";
  }
}
/*

*/
