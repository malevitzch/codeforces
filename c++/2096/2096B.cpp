#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> l(n);
  vector<long long> r(n);
  for(long long& x : l) cin >> x;
  for(long long& x : r) cin >> x;
  vector<long long> v(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(l[i] < r[i]) {
      swap(l[i], r[i]);
    }
  }
  sort(l.begin(), l.end(), greater<int>());
  sort(r.begin(), r.end(), greater<int>());
  for(int i = 0; i < n; i++) {
    ans += l[i];
  }
  for(int i = 0; i < k - 1; i++) {
    ans += r[i];
  }
  ans++;
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
