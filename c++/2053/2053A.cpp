#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve(int n, vector<int> v)
{
  for(int i = 1; i < n; i++) 
  {
    if(2 * min(v[i-1], v[i]) > max(v[i-1], v[i]))
    {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main()
{
  if(!DEBUG)
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;
    solve(n, v);
  }
}
/*

*/
