#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<vector<int>> m)
{
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    int mn = 0;
    for(int j = 0; i + j < n; j++)
    {
      mn = min(mn, m[j][i+j]);
      cout<<m[j][i+j]<<" ";
    }
    cout<<"!\n";
    if(mn < 0)
    {
      ans += abs(mn);
    }
  }
  cout<<"["<<ans<<"]"<<"\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)
  {
    vector<vector<int>> m;
    int n;
    cin>>n;
    m.resize(n);
    for(int i = 0; i < n; i++)
    {
      m[i].resize(n);
      for(int j = 0; j < n; j++)
      {
        cin>>m[i][j];
      }
    }
    solve(n, m);
  }
}
