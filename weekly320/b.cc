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
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &q) {
    int n = q.size();
    set<int> st;
    function<void(TreeNode *)> dfs = [&](TreeNode *u) {
      if (!u) {
        return;
      }
      st.insert(u->val);
      dfs(u->left);
      dfs(u->right);
    };
    dfs(root);
    vector<vector<int>> ans(n, vector<int>{-1, -1});
    for (int i = 0; i < n; ++i) {
      auto it = st.lower_bound(q[i]);
      if (it != st.end()) {
        ans[i][1] = *it;
      }
      it = st.upper_bound(q[i]);
      if (it != st.begin()) {
        ans[i][0] = *prev(it);
      }
    }
    return ans;
  }
};