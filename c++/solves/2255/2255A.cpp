#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll  = long long;
using ull = unsigned long long;

using ipair  = pair<int, int>;
using llpair = pair<ll, ll>;

using vi   = vector<int>;
using vb   = vector<bool>;
using vll  = vector<long long>;
using vull = vector<unsigned long long>;
using vstr = vector<string>;

#define bit(x,i) (x&(1LL<<i))

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

template<typename T>
vector<vector<T>> mtrx(size_t h, size_t l, T val = T()) {return vector<vector<T>>(h, vector<T>(l, val));}

void solve() {
  int n, k;
  cin >> n >> k;
  std::string s;
  cin >> s;
  int ans[2] = {0, 0};
  for(int i = 0; i < 2 * n; i++) {
    char nxt = s[(i + 1) % (2 * n)]; 
    if(s[i] == '1') {
      if(nxt == '1') {
          ans[1 - i % 2]++;
      } else {
          ans[i % 2]++;  
      }
    }
  }
  cout << ans[0] << " " << ans[1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t = inp();
  while(t--) solve();
}
/*

*/
