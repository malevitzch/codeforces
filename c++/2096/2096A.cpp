#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int top_index = n;
  int bot_index = 1;
  vector<int> heights(n);
  for(int i = n - 1; i > 0; i--) {
    if(s[i-1] == '>') {
      heights[i] = top_index--;
    } else {
      heights[i] = bot_index++;
    }
  }
  heights[0] = bot_index;
  for(auto x : heights) {
    cout << x << " ";
  } 
  cout << "\n";
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
