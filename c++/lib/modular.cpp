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
