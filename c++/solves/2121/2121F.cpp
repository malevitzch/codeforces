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

struct vals {
  int un = 0;
  int vetted = 0;
  int last_vetted = 0;
};

ll getAns(vll segment, ll sum, ll mx) {
  ll ans = 0;
  map<ll, vals> values;
  values[0] = {1, 0, 0};
  ll pref = 0;
  int last_vet = 0;
  for(ll x : segment) {
    pref += x;

    if(x == mx) {
      last_vet++;
    }

    if(values[pref - sum].last_vetted < last_vet) {
      values[pref - sum].last_vetted = last_vet;
      values[pref - sum].vetted += values[pref - sum].un;
      values[pref - sum].un = 0;
    }
    ans += values[pref - sum].vetted;



    if(!values.count(pref)) {
      values[pref].last_vetted = last_vet;
    }

    if(values[pref].last_vetted < last_vet) {
      values[pref].last_vetted = last_vet;
      values[pref].vetted += values[pref].un;
      values[pref].un = 0;
    }
    values[pref].un += 1;
  }
  return ans;
}

void solve() {
  int n = inp();
  ll sum = inp();
  ll mx = inp();
  vll num(n);
  for(auto& x : num) cin >> x;
  vector<vll> segments;
  vll segment;
  for(auto& x : num) {
    if(x > mx) {
      if(!segment.empty()) segments.push_back(segment);
      segment.clear();
    } else {
      segment.push_back(x);
    }
  }
  if(!segment.empty()) segments.push_back(segment);

  ll ans = 0;
  for(auto& segment : segments) {
    ans += getAns(segment, sum, mx);
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
