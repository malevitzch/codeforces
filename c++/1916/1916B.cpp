#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;

int myGCD(int a, int b) {
  if(a == 0) {
    return b;
  }
  return myGCD(b % a, a);
}

void solve() {
  long long a, b;
  cin >> a >> b;
  if(b % a == 0) {
    cout << b * (b / a) << "\n";
    return;
  }
  long long gcd = myGCD(a, b);
  cout << (a * b) / gcd << "\n";
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
