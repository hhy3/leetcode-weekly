#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int deleteGreatestValue(vector<vector<int>> &a) {
    for (auto &v : a) {
      sort(v.begin(), v.end());
    }
    int m = a.size(), n = a[0].size();
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      int mx = 0;
      for (int i = 0; i < m; ++i) {
        mx = max(mx, a[i][j]);
      }
      ans += mx;
    }
    return ans;
  }
};
