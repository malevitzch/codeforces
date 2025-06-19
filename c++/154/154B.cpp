#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;


  vector<vector<int>> prime_divisors(n+1);
  for(int i = 2; i <= n; i++) {
    if(prime_divisors[i].empty()) {
      for(int j = i; j <= n; j+=i) {
        prime_divisors[j].push_back(i);
      }
    }
  }
  map<int, int> divisors;
  set<int> on;
  for(int i = 0; i < m; i++) {
    string op;
    int val;
    cin >> op >> val;
    if(op == "-") {
      if(on.find(val) == on.end()) {
        cout << "Already off\n";
      }
      else {
        cout << "Success\n";
        for(int div : prime_divisors[val]) {
          divisors.erase(div);
        }
        on.erase(val);
      }
    }
    else {
      if(on.find(val) != on.end()) {
        cout << "Already on\n";
      }
      else {
        bool success = true;
        for(int div : prime_divisors[val]) {
          if(divisors.find(div) != divisors.end()) {
            success = false;
            cout << "Conflict with " << divisors[div] << "\n";
            break;
          }
        }
        if(success) {
          on.insert(val);
          for(int div : prime_divisors[val]) {
            divisors[div] = val;
          }
          cout << "Success\n";
        }
      }
    }
  }
}
