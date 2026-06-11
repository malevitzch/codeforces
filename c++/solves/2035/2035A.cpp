#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve(long long n, long long m, long long r, long long c)
{
  long long ans = n*m - ((r-1)*m+c) + (n - r)*(m-1) ;
  cout<<ans<<"\n";
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
    int n, m, r, c;
    cin>>n>>m>>r>>c;
    solve(n, m, r, c);
  }
}
/*

*/
