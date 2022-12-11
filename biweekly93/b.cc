#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxStarSum(vector<int> &a, vector<vector<int>> &edges, int k) {
    int n = a.size();
    vector<vector<pair<int, int>>> G(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      G[u].push_back({v, a[v]});
      G[v].push_back({u, a[u]});
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
      sort(G[i].begin(), G[i].end(),
           [](auto &lhs, auto &rhs) { return lhs.second > rhs.second; });
      int sum = a[i], cnt = 0;
      for (auto [v, w] : G[i]) {
        if (w >= 0 && cnt < k) {
          cnt++;
          sum += w;
        } else {
          break;
        }
      }
      ans = max(ans, sum);
    }
    return ans;
  }
};