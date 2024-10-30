#include <bits/stdc++.h>
using namespace std;

long long p = 1e9 + 7;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long n, k;
    cin>>n>>k;
    long long f1 = 0;
    long long f2 = 1;
    long long first = 0;
    while(1)
    {
      long long temp = f2;
      f2 = (f1 + f2) % k;
      f1 = temp % k;
      first++;
      if(f1 == 0) break;
    }
    cout << ((n % p) * (first % p)) % p << "\n"; 
  }
}
