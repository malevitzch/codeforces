#include <bits/stdc++.h>

using namespace std;

const long long modulo = 1e9 + 7;

struct Matrix {
  int n;
  vector<vector<long long>> data;
  Matrix(int n) : n(n), data(vector<vector<long long>>(n, vector<long long>(n))) {
  }
  Matrix operator*(const Matrix& m) const {
    Matrix result(n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          result.data[i][j] = (result.data[i][j] + (data[i][k] * m.data[k][j]) % modulo) % modulo;
        }
      }
    }
    return result;
  }
  static Matrix identity(int n) {
    Matrix matrix(n);
    for(int i = 0; i < n; i++) {
      matrix.data[i][i] = 1;
    }
    return matrix;
  }
};

Matrix expo(Matrix matrix, long long exponent) {
  if(exponent == 0) {
    return Matrix::identity(matrix.n);
  }
  if(exponent % 2) {
    return matrix * expo(matrix * matrix, exponent / 2);
  }
  return expo(matrix * matrix, exponent / 2);
}

int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  Matrix matrix(m);
  string s;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      matrix.data[i][j] = 1;
    }
  }

  for(int i = 0; i < k; i++) {
    cin >> s;
    int x = s[0];
    int y = s[1];
    if( x >= 'a' ) {
      x -= 'a';
    } else {
      x -= 'A' - 26;
    }
    if( y >= 'a' ) {
      y -= 'a';
    } else {
      y -= 'A' - 26;
    }
    matrix.data[x][y] = 0;
  }
  matrix = expo(matrix, n-1);
  long long ans = 0;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      ans = (ans + matrix.data[i][j]) % modulo;
    }
  }
  cout << ans << "\n";
}
