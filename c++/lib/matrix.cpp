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
  vector<long long>& operator[](int i) {
    return data[i];
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
