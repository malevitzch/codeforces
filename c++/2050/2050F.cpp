#include <bits/stdc++.h>
#define DEBUG false

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG
using namespace std;

const int K = 25;

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for(int& x : v) cin >> x;
  vector<int> diff;
  for(int i = 1; i < n; i++) diff.push_back(abs(v[i] - v[i-1]));

  vector<vector<int>> gcds(K+1, vector<int>(n-1, 0));
  std::copy(diff.begin(), diff.end(), gcds[0].begin());
  for(int i = 1; i <= K; i++) {
    for(int j = 0; j + (1 << i) <= n-1; j++) {
      gcds[i][j] = gcd(gcds[i-1][j], gcds[i-1][j + (1 << (i-1)) ]);
    }
  }

  int lg[n+10];
  lg[1] = 0;
  for(int i = 2; i <= n+10; i++) {
    lg[i] = lg[i/2] + 1;
  }

  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if(l == r) {
      cout << "0 ";
      continue;
    }

    l--;
    r--;
    r--;
    int s = log2_floor(r - l + 1);

    int range_gcd = gcd(gcds[s][l], gcds[s][r - (1 << s) + 1]);

    cout << range_gcd << " ";

  }
  cout << "\n";
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
    solve();
  }
}
/*

*/
