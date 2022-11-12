#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mostProfitablePath(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {
    int n = amount.size();
    vector<vector<int>> G(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      G[u].push_back(v);
      G[v].push_back(u);
    }
    vector<int> f(n), pa(n), height(n);
    function<void(int, int)> dfs = [&](int u, int p) {
      for (auto &v : G[u]) {
        if (v != p) {
          height[v] = height[u] + 1;
          pa[v] = u;
          dfs(v, u);
        }
      }
    };
    dfs(0, 0);
    for (int u = bob; u; u = pa[u]) {
      if (height[u] * 2 == height[bob]) {
        amount[u] /= 2;
      } else if (height[u] * 2 > height[bob]) {
        amount[u] = 0;
      }
    }
    int ans = INT_MIN;
    f[0] = amount[0];
    function<void(int, int)> dfs2 = [&](int u, int p) {
      if (u > 0 && G[u].size() == 1) {
        ans = max(ans, f[u]);
      }
      for (auto &v : G[u]) {
        if (v != p) {
          f[v] = f[u] + amount[v];
          dfs2(v, u);
        }
      }
    };
    dfs2(0, 0);
    return ans;
  }
};