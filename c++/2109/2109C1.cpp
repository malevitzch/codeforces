#include <bits/stdc++.h>
#include <ostream>
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

void findX(ll n) {
  for(ll x : {8, 4, 2, 1}) {
    cout << "add " << -x << "\n";
    cout.flush();
    int ok;
    cin >> ok;
  }
  cout << "add " << (n - 1) << "\n";
  cout.flush();
  int ok;
  cin >> ok;
}

void solve() {
  ll n = inp();
  for(int i = 0; i < 2; i++) {
    cout << "digit\n";
    cout.flush();
    int x;
    cin >> x;
  }
  findX(n);
  cout << "!\n";
  cout.flush();
  int ok;
  cin >> ok;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}
/*

*/
