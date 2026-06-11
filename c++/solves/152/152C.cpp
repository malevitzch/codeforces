#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


const long long p = 1e9 + 7;

int main()
{
  if(!DEBUG)
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int n, m;
  cin >> n >> m;
  vector<string> names(n);
  for(string& name : names) cin >> name;
  long long ans = 1;
  for(int i = 0; i < m; i++) {
    unordered_set<char> have;
    for(int j = 0; j < n; j++) have.insert(names[j][i]);
    ans = (ans * have.size()) % p; 
  }
  cout << ans << "\n";
}
/*

*/
