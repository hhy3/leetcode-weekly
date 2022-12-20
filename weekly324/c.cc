#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    vector<int> deg(n);
    vector<unordered_set<int>> G(n);
    for (auto& e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      G[u].insert(v);
      G[v].insert(u);
      deg[u]++;
      deg[v]++;
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      if (deg[i] % 2) {
        a.push_back(i);
      }
    }
    int cnt = a.size();
    if (cnt == 0) {
      return true;
    } else if (cnt == 2) {
      if (!G[a[0]].count(a[1])) {
        return true;
      }
      for (int i = 0; i < n; ++i) {
        if (i == a[0] || i == a[1]) {
          continue;
        }
        if (!G[i].count(a[0]) && !G[i].count(a[1])) {
          return true;
        }
      }
      return false;
    } else if (cnt == 4) {
      sort(a.begin(), a.end());
      do {
        if (!G[a[0]].count(a[1]) && !G[a[2]].count(a[3])) {
          return true;
        }
      } while (next_permutation(a.begin(), a.end()));
      return false;
    } else {
      return false;
    }
  }
};