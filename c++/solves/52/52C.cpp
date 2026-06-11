#include <bits/stdc++.h>
#include <vector>
using namespace std;

template<typename V>
struct Node {
  V val;
  bool id = true;
  Node(V value) : val(value), id(false) {}
  Node() = default;
};

int cpow(int x) {
  int res = 1;
  while(res < x) res *= 2;
  return res;
}

// Combine : (left: V&) -> (right: V&) -> V
// Combine should recalculate the values taking into account lazy propagation values
// Pushdown : (parent: V&) -> (left: V*) -> (right: V*) -> void
// Pushdown should handle nullptr children
template<typename V, auto Combine, auto Pushdown>
struct SegmentTree {
  using Node_t = Node<V>;

  Node_t* vals;
  int SIZE;

  Node_t& left(int index) {
    return vals[2*index];
  }

  Node_t& right(int index) {
    return vals[2*index+1];
  }

  Node_t comb(Node_t l, Node_t r) {
    if(l.id) return r;
    else if(r.id) return l;
    return Node_t(Combine(l.val, r.val));
  }

  void refresh(int pos) {
    if(pos >= SIZE) return;
    if(left(pos).id) vals[pos] = left(pos);
    else if(right(pos).id) vals[pos] = right(pos);
    else vals[pos] = comb(left(pos), right(pos));
  }

  void fix(int pos) {
    pos /= 2;
    while(pos) {
      refresh(pos);
      pos/=2;
    }
  }

  void pushdown(int index) {
    if(index >= SIZE) {Pushdown(vals[index].val, nullptr, nullptr);}
    else Pushdown(vals[index].val, &left(index).val, &right(index).val);
  }

  SegmentTree(int size) {
    SIZE = cpow(size);
    vals = new Node_t[2 * SIZE];
  }

  SegmentTree(vector<V> values) {
    SIZE = cpow(values.size());
    vals = new Node_t[2 * SIZE];
    for(int i = 0; i < values.size(); i++) {
      vals[i + SIZE] = Node_t(values[i]);
    }
    for(int i = SIZE + 1; i >= 1; i--) {
      refresh(i);
    }
  }

  void insert(int index, V val) {
    index = SIZE + index;
    pushdown(index);
    vals[index] = Node_t(val);
    fix(index);
  }

  Node_t query_segment(int l, int r) {
    return recursive_seg_query(1, l, r, 0, SIZE - 1);
  }

  void operation_segment(int l, int r, void (*operation)(V&, void*), void* arg) {
    recursive_seg_operation(1, l, r, 0, SIZE - 1, operation, arg);
  }

  Node_t recursive_seg_query(int index, int target_l, int target_r, int l, int r) {
    pushdown(index);
    if(target_l > r || target_r < l) {
      return Node_t();
    }
    if(target_r >= r && target_l <= l) {
      return vals[index];
    }

    return comb(
      recursive_seg_query(2*index, target_l, target_r, l, (l + r) / 2),
      recursive_seg_query(2*index+1, target_l, target_r, (l + r) / 2 + 1, r)
    );
  }

  void recursive_seg_operation(int index, int target_l, int target_r, int l, int r, void (*operation)(V&, void*), void* arg) {
    pushdown(index);
    if(target_l > r || target_r < l) return;
    if(target_r >= r && target_l <= l) {
      (*operation)(vals[index].val, arg);
      pushdown(index);
    } else {
      recursive_seg_operation(2*index, target_l, target_r, l, (l + r) / 2, operation, arg);
      recursive_seg_operation(2*index+1, target_l, target_r, (l + r) / 2 + 1, r, operation, arg);
      refresh(index);
    }
  }

  ~SegmentTree() {
    delete vals;
  }
};

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

void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}
void answer(bool b) {b ? YES() : NO();}
ll inp() {ll x; cin >> x; return x;}
ll& inp(ll& x) {cin >> x; return x;}
int& inp(int& x) {cin >> x; return x;}

template<typename T>
vector<vector<T>> mtrx(size_t h, size_t l, T val = T()) {return vector<vector<T>>(h, vector<T>(l, val));}

struct Val {
  ll mn = 0;
  ll pd = 0;
  Val(ll x) : mn(x) {}
  Val() = default;
};

Val cb(Val& v1, Val& v2) {
  Val v;
  v.mn = min(v1.mn + v1.pd, v2.mn + v2.pd);
  return v;
}

void pd(Val& v, Val* l, Val* r) {
  if(l) l->pd += v.pd;
  if(r) r->pd += v.pd;
  v.mn += v.pd;
  v.pd = 0;
}

void op(Val& val, void* v) {
  val.pd += *((int*) v);
}

void solve() {
  int n = inp();
  vector<Val> v(n);
  for(auto& x : v) cin >> x.mn;
  SegmentTree<Val, cb, pd> t(v);
  int m;
  cin >> m;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for(int i = 0; i < m; i++) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> v;
    int x;
    while(ss >> x) {
      v.push_back(x);
    }
    int lg = v[0];
    int rg = v[1];
    if(v.size() > 2) {
      int x = v[2];
      if(lg <= rg) {
        t.operation_segment(lg, rg, op, &x);
      } else {
        t.operation_segment(0, rg, op, &x);
        t.operation_segment(lg, n - 1, op, &x);
      }
    } else {
      if(lg <= rg) {
        cout << t.query_segment(lg, rg).val.mn << "\n";
      } else {
        cout << min(t.query_segment(0, rg).val.mn, t.query_segment(lg, n - 1).val.mn) << "\n";
      }
    }
  }
}

int main() {
  if(!DEBUG) {ios_base::sync_with_stdio(0); cin.tie(0);}
  solve();
}
/*

*/
