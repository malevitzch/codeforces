#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
  if(n % 2) cout<<"Kosuke\n"; else cout<<"Sakurako\n";
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    solve(n);
  }
}
