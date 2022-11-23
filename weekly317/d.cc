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

class Solution {
public:
  vector<int> treeQueries(TreeNode *root, vector<int> &qs) {
    int q = qs.size();
    vector<int> ans(q);
    for (auto &x : qs) {
      x--;
    }
    int n = 0;
    map<int, TreeNode *> mp;
    function<void(TreeNode *)> dfs = [&](TreeNode *u) {
      if (!u) {
        return;
      }
      n = max(n, u->val);
      mp[u->val - 1] = u;
      dfs(u->left);
      dfs(u->right);
    };
    dfs(root);
    vector<vector<int>> G(n);
    for (int i = 0; i < n; ++i) {
      auto u = mp[i];
      if (u->left) {
        G[i].push_back(u->left->val - 1);
      }
      if (u->right) {
        G[i].push_back(u->right->val - 1);
      }
    }
    vector<int> L(n), R(n), height(n);
    int T = 0;
    function<void(int, int)> dfs2 = [&](int u, int h) {
      height[T] = h;
      L[u] = T++;
      for (auto v : G[u]) {
        dfs2(v, h + 1);
      }
      R[u] = T;
    };
    dfs2(root->val - 1, 0);
    vector<int> f(n + 2), g(n + 2);

    for (int i = 1; i <= n; ++i) {
      f[i] = max(f[i - 1], height[i - 1]);
    }
    for (int i = n; i >= 1; --i) {
      g[i] = max(g[i + 1], height[i - 1]);
    }
    for (int i = 0; i < q; ++i) {
      int l = L[qs[i]], r = R[qs[i]];
      ans[i] = max(f[l], g[r + 1]);
    }
    return ans;
  }
};
