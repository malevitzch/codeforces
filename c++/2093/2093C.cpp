#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


bool isPrime(long long x) {
  if(x <= 1) return false;
  for(long long i = 2; i*i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}

void solve() {
  long long x;
  int k;
  cin >> x >> k;
  if(x == 1) {
    string s = "";
    for(int i = 0; i < k; i++) {
      s += "1";
    }
    long long val = stoi(s);
    cout << (isPrime(val) ? "YES" : "NO") << "\n";
    return;
  }
  if(k > 1 || !isPrime(x)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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
