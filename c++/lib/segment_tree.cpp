#include <bits/stdc++.h>
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
    while(pos /= 2 >= 1) refresh(pos);
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

  Node_t query_point(int index) {

  }
  Node_t query_segment(int l, int r) {
    return recursive_seg_query(1, l, r, 0, SIZE - 1);
  }

  Node_t recursive_seg_query(int index, int target_l, int target_r, int l, int r) {
    if(index >= SIZE) {Pushdown(vals[index].val, nullptr, nullptr);}
    else Pushdown(vals[index].val, &left(index).val, &right(index).val);
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

  ~SegmentTree() {
    delete vals;
  }
};
