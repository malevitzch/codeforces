#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string s) {
  int n = s.length();
  vector<int> res(n);
  for(int i = 1; i < n; i++) {
    int j = res[i-1];
    while(j > 0 && s[i] != s[j]) j = res[j-1];
    if(s[i] == s[j]) j++;
    res[i] = j;
  }
  return res;
}

vector<int> find_all_occurences(string pattern, string str) {
  string s = pattern + "$" + str;
  auto pf = prefix_func(s);
  vector<int> ans;
  for(int i = 0; i < s.size(); i++) {
    if(pf[i] == pattern.size()) ans.push_back(i - 2 * pattern.size());
  }
  return ans;
}
