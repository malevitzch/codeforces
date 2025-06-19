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
  vector<long long>& operator[](int index) {
    return data[index];
  }
  static Matrix identity(int n) {
    Matrix matrix(n);
    for(int i = 0; i < n; i++) {
      matrix.data[i][i] = 1;
    }
    return matrix;
  }
};

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
  for (int i = 0; i < m.n; ++i) {
    for (int j = 0; j < m.n; ++j) {
      os << m.data[i][j] << (j + 1 == m.n ? '\n' : ' ');
    }
  }
  return os;
}


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
  long long n;
  int m;
  cin >> n >> m;
  if(n < m) {
    cout << 1 << "\n";
    return 0;
  }
  Matrix matrix(m);
  for(int i = 0; i < m - 1; i++) {
    matrix[i][i+1] = 1;
  }
  matrix[m-1][m-1] = 1;
  matrix[m-1][0] = 1;
  matrix = expo(matrix, n);
  long long ans = 0;
  for(int i = 0; i < m; i++) {
    ans = (ans + matrix[0][i]) % modulo;
  }
  cout << ans << "\n";
}
