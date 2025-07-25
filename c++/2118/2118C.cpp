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

#define bit(x,i) (x&(1LL<<i))

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
  ll n = inp();
  ll k = inp();
  vll v(n);
  vll costs;
  ll ans = 0;
  for(ll& x : v) {
    cin >> x;
    for(ll i = 0; i < 63; i++) {
      if(x & (1LL << i)) {
        ans++;
      } else {
        costs.push_back(1LL << i);
      }
    }
  }
  sort(costs.begin(), costs.end());
  int i = 0;
  while(i < costs.size() && k >= costs[i]) {
    ans++;
    k -= costs[i];
    i++;
  }
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
