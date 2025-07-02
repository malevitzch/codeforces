#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define DEBUG false

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


void solve() {
  int n, s;
  cin >> n >> s;
  vi v(n);
  for(auto& x : v) cin >> x;
  int mx = *max_element(v.begin(), v.end());
  int mn = *min_element(v.begin(), v.end());
  if(mx <= s) {
    cout << s - mn << "\n";
    return;
  }
  if(mn >= s) {
    cout << mx - s << "\n";
    return;
  }
  cout << (mx - mn) + min(s - mn, mx - s) << "\n";
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
