#include <bits/stdc++.h>

template<typename T>
struct Point {
  T x, y;
  Point(T x, T y) : x(x), y(y) {}
  Point operator+(const Point p) const { return Point(x + p.x, y + p.y); }
  Point& operator+=(const Point p) { x += p.x; y += p.y; return *this; }
};

typedef Point<float> fPoint;
typedef Point<double> dPoint;

// Ax + By + C = 0
template<typename T>
struct Line {
  T A, B, C;
  Line(T A, T B, T C) : A(A), B(B), C(C) {}
  Line(Point<T> p1, Point<T> p2) : A(p2.y-p1.y), B(p1.x-p2.x), C(p2.x*p1.y-p1.x*p2.y) {}
};

