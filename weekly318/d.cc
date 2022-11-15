#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minimumTotalDistance(vector<int> &robot,
                                 vector<vector<int>> &factory) {
    int n = robot.size(), m = factory.size();
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    vector<vector<int64_t>> b(m + 1, vector<int64_t>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        b[i][j] = b[i][j - 1] + abs(robot[j - 1] - factory[i - 1][0]);
      }
    }
    vector<vector<int64_t>> f(m + 1, vector<int64_t>(n + 1, 1e15));
    f[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= min(j, factory[i - 1][1]); ++k) {
          f[i][j] = min(f[i][j], f[i - 1][j - k] + b[i][j] - b[i][j - k]);
        }
      }
    }
    return f[m][n];
  }
};