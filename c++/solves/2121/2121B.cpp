#include <algorithm>
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
  string s;
  cin >> n >> s;
  vi counts(26);
  if(s[0] == s.back()) {
    counts[s[0] - 'a']++;
  } else {
    counts[s[0] - 'a']++; 
    counts[s.back() - 'a']++;
  }
  for(int i = 1; i < n-1; i++) {
    counts[s[i] - 'a']++;
  }
  cout << ((*max_element(counts.begin(), counts.end()) >= 2) ? "Yes\n" : "No\n");
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
