#include <bits/stdc++.h>
using namespace std;

#define DEBUG false

#define ll long long
#define ull unsigned long long

#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vstr vector<string>

#define bit(x,i) (x&(1<<i))

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG


void solve() {
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  for(int& x : a) cin >> x;
  for(int& x : b) cin >> x;

  map<int, vi> nums_a;
  map<int, vi> nums_b;
  set<int> nums;
  for(int i = 0; i < n; i++) {
    nums_a[a[i]].push_back(i);
    nums_b[b[i]].push_back(i);
    nums.insert(a[i]);
    nums.insert(b[i]);
  }
  int matches = 0;

  for(int i = 0; i < n; i++) {
    if(a[i] == b[i]) {
      matches = max(matches, i + 1);
    }
  }

  // We should search for last instead of first actually
  for(int x : nums) {
    vi v1 = nums_a[x];
    vi v2 = nums_b[x];
    {
      int last_even = -1;
      int last_odd = -1;

      for(int i = 0; i < v1.size(); i++) {
        if(v1[i] % 2 == 0) {
          last_even = max(v1[i], last_even);
        } else {
          last_odd = max(v1[i], last_odd);
        }
      }
      for(int i = 0; i < v2.size(); i++) {
        if(v2[i] % 2 == 1) {
          last_even = max(v2[i], last_even);
        } else {
          last_odd = max(v2[i], last_odd);
        }
      }
      for(int i = 0; i < v1.size(); i++) {
        int ind = v1[i];
        if(ind % 2 == 0) {
          if(last_odd >= ind) {
            matches = max(ind + 1, matches);
          }
          if(last_even > ind + 1) {
            matches = max(ind + 1, matches);
          }
        } else {
          if(last_even >= ind) {
            matches = max(ind + 1, matches);
          }
          if(last_odd > ind + 1) {
            matches = max(ind + 1, matches);
          }
        }
      }
      for(int i = 0; i < v2.size(); i++) {
        int ind = v2[i];
        if(ind % 2 == 1) {
          if(last_odd >= ind) {
            matches = max(ind + 1, matches);
          }
          if(last_even > ind + 1) {
            matches = max(ind + 1, matches);
          }
        } else {
          if(last_even >= ind) {
            matches = max(ind + 1, matches);
          }
          if(last_odd > ind + 1) {
            matches = max(ind + 1, matches);
          }
        }
      }
    }
    //swap(v1, v2);
  }
  cout << matches << "\n";
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
