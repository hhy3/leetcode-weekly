#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxPoints(vector<vector<int>> &a, vector<int> &queries) {
    int m = a.size(), n = a[0].size();
    using p = pair<int, pair<int, int>>;
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({a[0][0], {0, 0}});
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    dist[0][0] = a[0][0];
    vector<vector<bool>> vis(m, vector<bool>(n));

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (q.size()) {
      auto [d, loc] = q.top();
      q.pop();
      auto [i, j] = loc;
      if (vis[i][j]) {
        continue;
      }
      vis[i][j] = true;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= m || y < 0 || y >= n) {
          continue;
        }
        int t = max(dist[i][j], a[x][y]);
        if (t < dist[x][y]) {
          dist[x][y] = t;
          q.push({t, {x, y}});
        }
      }
    }
    const int M = 1e6;
    vector<int> cnt(M + 1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt[dist[i][j]]++;
      }
    }
    for (int i = 1; i <= M; ++i) {
      cnt[i] += cnt[i - 1];
    }
    vector<int> ans;
    for (auto q : queries) {
      ans.push_back(cnt[q - 1]);
    }
    return ans;
  }
};
