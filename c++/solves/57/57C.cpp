#include <bits/stdc++.h>
using namespace std;

long long p = 1e9 + 7;

long long factorial(int n) {
  static vector<long long> values = {1};
  while(n >= values.size()) {
    values.push_back((values.back() * values.size()) % p);
  }
  return values[n];
}

long long fastExpo(long long x, long long y) {
  if(y == 0) return 1;
  if(y % 2) return ((x % p) * fastExpo((x % p) * (x % p), y/2)) % p;
  return fastExpo(( (x % p) * (x % p) ) % p, y/2);
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
  long long n;
  cin >> n;
  long long ans = p - n;

  // We want to pick a subset but with repetitions

  ans = (ans + (2*binom(n + n - 1,  n)) % p) % p;
  cout << ans << "\n";
}

int main() {
  if(!DEBUG) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t(1);
  while(t--) {
    solve();
  }
}
/*

*/
