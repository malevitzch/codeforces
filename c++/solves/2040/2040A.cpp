#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;


void solve(int n, int k, vector<int> v)
{
  map<int, vector<int> > counts;
  for(int i = 0 ; i < n; i++) counts[v[i] % k].push_back(i);
  for(auto&[key, val] : counts) 
  {
    if(val.size() == 1)
    {
      cout<<"YES\n"<<val[0]+1<<"\n";
      return;
    }
  }
  cout<<"NO\n";
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
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int& x : v) cin>>x;
    solve(n, k, v);
  }
}
/*

*/
