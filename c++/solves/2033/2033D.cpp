#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> v)
{
  int ans = 0;
  map<long long, int> last;
  last[0] = -1;
  int end = -1;
  long long sum = 0;
  for(int i = 0; i < n; i++)
  {
    if(v[i] == 0)
    {
      ans++;
      end = i;
      last[sum] = i;
      continue;
    }
    sum += v[i];
    if(last.find(sum) != last.end())
    {
      if(last[sum] >= end)
      {
        ans++;
        end = i;
      }
    }
    last[sum] = i;
  }
  cout<<ans<<"\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
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
