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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int q = inp();
  vector<string> strings(q);
  for(string& s : strings) cin >> s;


  vector<vi> next(k);
  for(int i = 0; i < k; i++) {
    next[i] = vector<int>(n, INT_MAX);
  }
  for(int c = 0; c < k; c++) {
    for(int i = n - 2; i >= 0; i--) {
      if(s[i+1] == 'a' + c) {
        next[c][i] = i + 1;
      } else {
        next[c][i] = next[c][i+1];
      }
    }
  }
  vector<int> ruin(n, INT_MAX);

  ruin[n-1] = 1;
  for(int i = n - 1; i >= 0; i--) {
    for(int c = 0; c < k; c++) {
      if(next[c][i] == INT_MAX) {
        ruin[i] = 1;
      } else {
        ruin[i] = min(ruin[next[c][i]] + 1, ruin[i]);
      }
    }
  }

  for(string st : strings) {
    int ans = 0;
    int i;
    if(st[0] == s[0]) {
      i = 0;
    } else {
      i = next[st[0] - 'a'][0];
    }

    for(int j = 1; j < st.size(); j++) {
      if(i == INT_MAX) break;
      i = next[st[j] - 'a'][i];
      if(i == INT_MAX) break;
    }
    if(i == INT_MAX) {
      cout << 0 << "\n";
    } else {
      cout << ruin[i] << "\n";
    }
  }
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
