#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


int solve(int n)
{
  if(n == 1) return 1;
  int cur = 1;
  int ans = 1;
  while(cur < n)
  {
    cur += cur+2;
    ans++;
  }
  return ans;
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
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    cout << solve(n) << "\n";
  }
}
/*

*/
