#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string s) {
  int n = s.length();
  vector<int> res(n);
  for(int i = 1; i < n; i++) {
    int j = res[i-1];
    while(j > 0 && s[i] != s[i]) j = res[j-1];
    if(s[i] == s[j]) j++;
    res[i] = j;
  }
  return res;
}
