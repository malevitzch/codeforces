#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve() {
  string s;
  cin >> s;
  int ans = 0;
  while(s.back() == '0') {
    s.pop_back();
    ans++;
  }
  ans += count_if(s.begin(), s.end()-1, [](char ch){return ch != '0';});
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
