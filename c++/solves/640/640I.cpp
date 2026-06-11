#include <bits/stdc++.h>
using namespace std;

long long expo(long long x, int exponent) {
  if(exponent <= 0) {
    return 1;
  }
  if(exponent % 2) {
    return x * expo(x*x, exponent / 2);
  }
  return expo(x*x, exponent / 2);
}

int main() {
  int n;
  cin >> n;
  long long ans = (24 * expo(4, n-3));
  if(n > 3) {
    ans += 36 * (n - 3) * expo(4, n-4);
  }
  cout << ans << "\n";
}
