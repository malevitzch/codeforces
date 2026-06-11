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

const ll p = 1e9 + 7;

ll factorial(int n) {
  static vll values = {1};
  while(n >= values.size()) {
    values.push_back((values.back() * values.size()) % p);
  }
  return values[n];
}

bool is_good(ll n, int a, int b) {
  while(n > 0) {
    if(n % 10 != a && n % 10 != b) {
      return false;
    }
    n /= 10;
  }
  return true;
}

long long fastExpo(long long x, long long y) {
  if(y == 0) return 1;
  if(y % 2) return ((x % p) * fastExpo((x % p) * (x % p), y/2)) % p;
  return fastExpo(((x % p)*(x % p)) % p, y/2);
}

long long inverse(long long x) {
  return fastExpo(x, p - 2);
}

long long binom(long long n, long long k) {
  if(k == 0 || k == n) {
    return 1;
  }
  return (((factorial(n) * inverse(factorial(k))) % p) * inverse(factorial(n - k))) % p;
}

void solve() {
  int a, b, n;
  cin >> a >> b >> n;
  long long ans = 0;
  for(ll i = 0; i <= n; i++) {
    long long x = i * a + b * (n - i);
    if(is_good(x, a, b)) {
      ans = (ans + binom(n, i)) % p;
    }
  }
  cout << ans << "\n";
}

int main() {
  if(!DEBUG) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  solve();
}
/*

*/
