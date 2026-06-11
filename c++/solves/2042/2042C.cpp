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
  ll k = inp();
  string s;
  cin >> s;
  int ans = 1;
  int cur_sum = 0;
  vector<int> sums;
  for(int i = n - 1; i > 0; i--) {
    cur_sum += (s[i] == '1' ? 1 : -1);
    sums.push_back(cur_sum);
  }
  sort(sums.begin(), sums.end(), greater<int>());
  ll cur = 0;
  for(int x : sums) {
    if(cur < k) {
      cur += x;
      ans++;
    }
  }
  if(cur < k) {
    cout << "-1\n";
    return;
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
