#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> v)
{
  int ans = 0;
  for(int i = 1; i < n/2; i++)
  {
    if(v[i] == v[i-1] || v[n - i - 1] == v[n - i]) swap(v[i], v[n-i-1]);
  }
  for(int i = 1; i < n; i++)
  {
    ans += (v[i]==v[i-1]);
  }
  cout<<ans<<"\n";
}

int main()
{
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
