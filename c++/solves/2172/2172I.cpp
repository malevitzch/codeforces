#include <bits/stdc++.h>
using namespace std;
#define DEBUG false

using ll  = long long;
using ull = unsigned long long;

using ipair  = pair<int, int>;
using llpair = pair<ll, ll>;

using vi   = vector<int>;
using vb   = vector<bool>;
using vll  = vector<long long>;
using vull = vector<unsigned long long>;
using vstr = vector<string>;

#define bit(x,i) (x&(1LL<<i))

#if DEBUG == 1
#include "debug_lib.cpp"
using namespace dbg;
#endif // DEBUG

constexpr float pi = 3.14159265358979323846;

const uint8_t skipChar = ' ';
inline int64_t __attribute__ ((
            always_inline, flatten, nothrow, hot 
        )) _readSignedInt64() {
            uint8_t c = (uint8_t) _getchar_nolock();
            for (;;) {
                if (c > skipChar) [[likely]] break;
                c = (uint8_t) _getchar_nolock();
            }
            bool sign = false;
            if (c == '-') {
                sign = true;
                c = (uint8_t) _getchar_nolock();
            }
            uint64_t o = c - '0';

            for (;;) {
                const int32_t r = _getchar_nolock();
                if (r == EOF) [[unlikely]] break;
                const uint8_t k = (uint8_t) r;
                if (k <= skipChar) [[unlikely]] break;
                o = 10 * o + k - '0';
            }
            return sign ? -(int64_t)o : (int64_t)o;
        }

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

template<typename T>
vector<vector<T>> mtrx(size_t h, size_t l, T val = T()) {return vector<vector<T>>(h, vector<T>(l, val));}
struct pt {
    float x, y;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

// The convex hull code is taken from
// https://cp-algorithms.com/geometry/convex-hull.html
int orientation(pt a, pt b, pt c) {
  float v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  if (v < 0) return -1; // clockwise
  if (v > 0) return +1; // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
  pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });
  sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
        < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
    return o < 0;
  });
  if (include_collinear) {
      int i = (int)a.size()-1;
      while (i >= 0 && collinear(p0, a[i], a.back())) i--;
      reverse(a.begin()+i+1, a.end());
  }

  vector<pt> st;
  for (int i = 0; i < (int)a.size(); i++) {
    while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.push_back(a[i]);
  }

  if (include_collinear == false && st.size() == 2 && st[0] == st[1])
    st.pop_back();

  a = st;
}


float dx = 0;
float cx = 0;
float cy = 0;
double smallestd;
pt p1;
pt p2;
bool win = false;

void find_area(pt a, pt b, float r) {
  float A = b.y - a.y;
  float B = a.x - b.x;
  float C = b.x * a.y - a.x * b.y;

  if(C * (A * cx + B * cy + C) <= 0 ) {
    win = true;
    return;
  }

  float d = C*C / (A*A + B*B);
  if(d < smallestd) {
    p1 = a;
    p2 = b;
  }
  smallestd = min((double) d, smallestd);
}

void solve() {
  int n;
  float r;
  n = _readSignedInt64();
  r = _readSignedInt64();
  smallestd = r*r;
  win = false;
  float mx = pi * r * r / 2;
  vector<pt> points;
  cx = 0;
  cy = 0;
  for(int i = 0; i < n; i++) {
    float a = _readSignedInt64();
    float b = _readSignedInt64();
    cx += a/n;
    cy += b/n;
    points.push_back({a, b});
  }
  if(n == 1) {
    cout << setprecision(17) << r * r * pi / 2 << "\n";
    return;
  }
  dx = sqrt(cx*cx + cy*cy);
  convex_hull(points);
  find_area(points[0], points[1], r);
  for(int i = 1; i < points.size(); i++) {
    find_area(points[i], points[(i + 1) % points.size()], r);
    if(win) {
      cout << setprecision(17) << r * r * pi / 2 << "\n";
      return;
      break;
    }
  }

  pt a = p1;
  pt b = p2;

  double A = b.y - a.y;
  double B = a.x - b.x;
  double C = b.x * a.y - a.x * b.y;

  double d = fabs(C) / sqrt(A*A + B*B);
  double c = d / r;
  double area = r*r * acos(d / r) - d * sqrt(r*r - d*d);
  cout << setprecision(17) << area << "\n";
}

int main() {
  if(!DEBUG) {ios_base::sync_with_stdio(0); cin.tie(0);}
  solve();
}
/*

*/
