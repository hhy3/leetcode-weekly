#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

namespace hy {

template <typename T = int64_t> struct Discretizer {
  std::map<T, int> mp;
  int sz = 0;

  explicit Discretizer(const std::vector<T> &v)
      : Discretizer(v.begin(), v.end()) {}

  template <typename Iter> Discretizer(Iter first, Iter last) {
    for (auto it = first; it != last; ++it) {
      mp[*it];
    }
    for (auto &[_, v] : mp) {
      v = sz++;
    }
  }

  int operator[](T x) { return mp[x]; }

  int size() { return sz; }
};

} // namespace hy

class Solution {
public:
  int minimumOperations(TreeNode *root) {
    map<int, vector<int>> levels;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *u, int d) {
      if (!u) {
        return;
      }
      levels[d].push_back(u->val);
      dfs(u->left, d + 1);
      dfs(u->right, d + 1);
    };
    dfs(root, 0);
    int ans = 0;

    for (auto &[k, v] : levels) {
      hy::Discretizer<int> dis(v.begin(), v.end());
      for (auto &x : v) {
        x = dis[x];
      }
      int m = v.size();
      int cnt = 0;
      vector<bool> vis(m);
      for (int i = 0; i < m; ++i) {
        if (!vis[i]) {
          cnt++;
          for (int u = i; !vis[u]; u = v[u])
            vis[u] = true;
        }
      }
    }
    return ans;
  }
};