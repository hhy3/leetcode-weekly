#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxPalindromes(string s, int k) {
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
      f[i][i] = 1;
      if (i < n - 1) {
        f[i][i + 1] = (s[i] == s[i + 1]);
      }
    }

    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
      }
    }

    vector<int> g(n + 1);
    int ans = 0;
    for (int i = k; i <= n; ++i) {
        g[i] = g[i-1];
      for (int j = i - k; j >= 0; --j) {
        if (f[j][i - 1]) {
          g[i] = max(g[i], g[j] + 1);
        }
      }
      ans = max(ans, g[i]);
    }
    return ans;
  }
};