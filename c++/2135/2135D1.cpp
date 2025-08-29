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
  int M = 1e5;
  cout << "? " << M;
  for(int i = 0; i < M; i++) {
    cout << " 330";
  }
  cout << "\n";

  cout.flush();
  
  int k1;
  cin >> k1;

  if(k1 == 0) {
    cout << "? " << M;
    for(int i = 0; i < M; i++) {
      cout << " 1";
    }
    cout << "\n";
    cout.flush();
    int k;
    cin >> k;

    for(int i = 1; i < 330; i++) {
      if( (M + i - 1) / i == k) {
        cout << "! " << i << "\n";
        cout.flush();
        return;
      }
    }
  } else {
    // Here we have W = 330 * k1 + r
    int k = 0;
    for(int i = 1; i < 330; i++) {
      if( (M + i - 1) / i == k1) {
        k = i;
        break;
      }
    }
    cout << "? " << 329 * 2;
    for(int i = 1; i < 330; i++) {
      cout << " " << 330 * k << " " << i;
    }
    cout << "\n";
    cout.flush();
    int x;
    cin >> x;
    int r = 329 - (x - 330);

    cout << "! " << 330 * k + r - 1 << "\n";
    cout.flush();
  }
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
