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
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& x : a) cin >> x;
  vector<int> prefmin(n);
  prefmin[0] = INT_MAX;
  vector<int> sufmax(n);
  sufmax[n-1] = INT_MIN;
  for(int i = 1; i < n; i++) {
    prefmin[i] = min(a[i-1], prefmin[i-1]);
  }
  for(int i = n - 2; i >= 0; i--) {
    sufmax[i] = max(a[i+1], sufmax[i+1]);
  }
  for(int i = 0; i < n; i++) {
    if(prefmin[i] > a[i] || sufmax[i] < a[i]) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << "\n";
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
