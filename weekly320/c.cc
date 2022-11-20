#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minimumFuelCost(vector<vector<int>> &edges, int K) {
    int n = edges.size() + 1;
    vector<vector<int>> G(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      G[u].push_back(v);
      G[v].push_back(u);
    }
    vector<int> sz(n), f(n);
    int64_t ans = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
      sz[u] = 1;
      for (auto v : G[u]) {
        if (v != p) {
          dfs(v, u);
          sz[u] += sz[v];
        }
      }
      f[u] = (sz[u] + K - 1) / K;
      if (u > 0) {
        ans += f[u];
      }
    };
    dfs(0, -1);
    return ans;
  }
};