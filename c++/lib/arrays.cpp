#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<long long> prefsum(vector<T>& v) {
  vector<long long> res = {0};
  res.insert(res.end(), v.begin(), v.end());
  for(int i = 2; i < res.size(); i++) res[i] += res[i-1];
  return res;
}

template<typename T>
vector<long long> sufsum(vector<T>& v) {
  vector<long long> res(v.begin(), v.end());
  res.push_back(0);
  for(int i = res.size() - 2; i >= 0; i--) res[i] += res[i+1];
  return res;
}

template<typename T>
struct scale_t {
  map<int, T> orig;
  vector<int> v;
};

template<typename T>
scale_t<T> rescale(vector<T> v) {
  set<T> values(v.begin(), v.end());
  scale_t<T> res;
  int i = 1;
  map<T, int> scaler;
  for(T& x : values) {
    res.orig[i] = x;
    scaler[x] = i;
    i++;
  }
  for(T& x : v) res.v.push_back(scaler[x]);
  return res;
}

