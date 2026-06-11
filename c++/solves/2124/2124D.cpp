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
  int k = inp();
  vi v(n);
  for(int& x : v) inp(x);
  map<int, int> cnt;
  for(int x : v) cnt[x]++;
 
  vi v1 = v;
  sort(v1.begin(), v1.end());
  map<int, int> smaller;
  for(int i = 0; i < n; i++) {
    if(i == 0 || v1[i-1] != v1[i]) {
      smaller[v1[i]] = i;
    }
  }
  int l = 0;
  int r = n - 1;
  while(l < r) {
    if(v[l] == v[r]) {
      l++;
      r--;
      continue;
    }
    if(v[l] > v[r]) {
      if(smaller[v[l]] + cnt[v[l]] >= k) {
        cnt[v[l]]--;
        l++;
      } else if(smaller[v[r]] + cnt[v[r]] >= k) {
        cnt[v[r]]--;
        r--;
      } else {
        NO();
        return;
      }
    } else {
      if(smaller[v[r]] + cnt[v[r]] >= k) {
        cnt[v[r]]--;
        r--;
      } else if(smaller[v[l]] + cnt[v[l]] >= k) {
        cnt[v[l]]--;
        l++;
      } else {
        NO();
        return;
      }
    }
  }
  YES();
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
