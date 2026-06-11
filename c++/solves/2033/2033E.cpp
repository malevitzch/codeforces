#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> v)
{
  vector<int> pos(n);
  for(int i = 0; i < n; i++)
  {
    pos[v[i] - 1] = i;
  }
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    if(v[i] != i+1 && v[v[i]-1] != i+1)
    {
      ans++;
      int i1(v[i]), i2(v[pos[pos[i]]]);
      swap(v[i], v[pos[pos[i]]]);
      swap(pos[i1-1], pos[i2-1]);
    }

  }
  cout<<ans<<"\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int& x : v) cin>>x;
    solve(n, v);
  }
}
