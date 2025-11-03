#include <bits/stdc++.h>
using namespace std;

template<typename T, typename V>
struct pq_el {
  T key;
  V val;
  int pos;
  bool operator<(const pq_el& e) const {
    return key < e.key; 
  }
};

template<typename T, typename V> 
struct prio_queue {

  vector<pq_el<T, V>*> mem;
  
  pq_el<T, V>* get(int index) { return mem[index - 1]; }
  bool exists(int index) { return index < mem.size(); }
  V getMin() { return *mem[0].val; }
  void deleteMin() {
    swap(mem[min], mem.back());
    mem.pop_back();
    int index = 1;
    // TODO: impl
  }
  void fixUp(int index) {
    // TODO: ???
  }
  void decreaseKey(pq_el<T, V>* el, T new_key) {
    while(el->pos != 1 || get(el->pos / 2).key < el->key) {
      swap(mem[el->pos - 1], mem[el -> pos / 2 - 1]);
      swap(mem[el->pos - 1]->pos, mem[el->pos / 2 - 1]->pos);
    }
    // TODO: impl
  }
  void insert(pq_el<T, V>* el) {
    // TODO: impl
  }

};
