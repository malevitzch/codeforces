#include <bits/stdc++.h>
using namespace std;

#define DEBUG false

#define ll long long
#define ull unsigned long long

#define ipair pair<int, int>
#define llpair pair<ll, ll>

#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vstr vector<string>

#define bit(x,i) (x&(1<<i))

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

void solve() {
  int n = inp();
  vector<vi> M(n, vi(n, 0));
  for(vi& v : M) {
    for(int& x : v) {
      cin >> x;
    }
  }
  vi a(n);
  for(int& x : a) inp(x);
  vi b(n);
  for(int& x : b) inp(x);

  vll dpA0(n, LLONG_MAX);
  vll dpA1(n, LLONG_MAX);
  dpA0[0] = 0;
  dpA1[0] = a[0];

  for(int i = 1; i < n; i++) {

    bool yes = true;
    for(int j = 0; j < n; j++) {
      if(M[i-1][j] == M[i][j]) {
        yes = false; break;
      }
    }
    if(yes) {
      if(dpA0[i-1] != LLONG_MAX) dpA0[i] = min(dpA0[i], dpA0[i-1]);
      if(dpA1[i-1] != LLONG_MAX) dpA1[i] = min(dpA1[i], dpA1[i-1] + a[i]);
    }

    yes = true;
    for(int j = 0; j < n; j++) {
      if(M[i-1][j] + 1 == M[i][j]) {
        yes = false; break;
      }
    }
    if(yes && dpA1[i-1] != LLONG_MAX) {
      dpA0[i] = min(dpA0[i], dpA1[i-1]);
    }

    yes = true;
    for(int j = 0; j < n; j++) {
      if(M[i-1][j] == M[i][j] + 1) {
        yes = false; break;
      }
    }
    if(yes && dpA0[i-1] != LLONG_MAX) {
      dpA1[i] = min(dpA1[i], a[i] + dpA0[i-1]);
    }
  }

  ll A = min(dpA0.back(), dpA1.back());
  if(A == LLONG_MAX) {
    cout << "-1\n";
    return;
  }

  vll dpB0(n, LLONG_MAX);
  vll dpB1(n, LLONG_MAX);
  dpB0[0] = 0;
  dpB1[0] = b[0];

  for(int i = 1; i < n; i++) {

    bool yes = true;
    for(int j = 0; j < n; j++) {
      if(M[j][i-1] == M[j][i]) {
        yes = false; break;
      }
    }
    if(yes) {
      if(dpB0[i-1] != LLONG_MAX) dpB0[i] = min(dpB0[i], dpB0[i-1]);
      if(dpB1[i-1] != LLONG_MAX) dpB1[i] = min(dpB1[i], dpB1[i-1] + b[i]);
    }

    yes = true;
    for(int j = 0; j < n; j++) {
      if(M[j][i-1] + 1 == M[j][i]) {
        yes = false; break;
      }
    }
    if(yes && dpB1[i-1] != LLONG_MAX) {
      dpB0[i] = min(dpB0[i], dpB1[i-1]);
    }

    yes = true;
    for(int j = 0; j < n; j++) {
      if(M[j][i-1] == M[j][i] + 1)  {
        yes = false; break;
      }
    }
    if(yes && dpB0[i-1] != LLONG_MAX) {
      dpB1[i] = min(dpB1[i], b[i] + dpB0[i-1]);
    }
  }

  ll B = min(dpB0.back(), dpB1.back());
  if(B == LLONG_MAX) {
    cout << "-1\n";
    return;
  }

  cout << A + B << "\n";


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
