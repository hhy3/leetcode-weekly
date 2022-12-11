#include <bits/stdc++.h>
using namespace std;

class Allocator {
public:
  struct Block {
    int l, r, id;
    friend bool operator<(const Block &lhs, const Block &rhs) {
      return lhs.l < rhs.l;
    }
  };

  int n;
  set<Block> st;

  Allocator(int n) { this->n = n; }

  int allocate(int size, int mID) {
    int pre = 0;
    for (auto [l, r, id] : st) {
      if (l - pre >= size) {
        st.insert({pre, pre + size, mID});
        return pre;
      } else {
        pre = r;
      }
    }
    if (n - pre >= size) {
      st.insert({pre, pre + size, mID});
      return pre;
    }
    return -1;
  }

  int free(int mID) {
    int ans = 0;
    for (auto it = st.begin(); it != st.end();) {
      if (it->id == mID) {
        ans += it->r - it->l;
        st.erase(it++);
      } else {
        it++;
      }
    }
    return ans;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */