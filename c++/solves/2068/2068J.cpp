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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int whites = 0;
  for(int i = 0; i < n; i++) {
    whites += (s[i] == 'W');
  }
  int first_whites = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'W') first_whites++; else break;
  }
  int last_red = 0;
  for(int i = 2*n - 1; i >= 0; i--) {
    if(s[i] == 'R') last_red++; else break;
  }
  answer(whites % 2 == 0 && first_whites * 2 >= whites && last_red * 2 >= whites);
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
