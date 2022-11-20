#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int beautifulPartitions(string s, int k, int mi) {
    int n = s.size();
    vector<int> a(n + 1);
    vector<int> pos;
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == '2' || s[i - 1] == '3' || s[i - 1] == '5' ||
          s[i - 1] == '7') {
        a[i] = 1;
      }
      if (i >= mi + 1 && i <= n - mi + 1 && a[i - 1] == 0 && a[i] == 1) {
        pos.push_back(i);
      }
    }

    if (k * mi > n || a[1] == 0 || a[n] == 1 || pos.size() < k - 1) {
      return 0;
    }
    int m = pos.size();
    pos.insert(pos.begin(), -1e9);
    vector<vector<int64_t>> f(m + 1, vector<int64_t>(k)),
        g(m + 1, vector<int64_t>(k));
    int64_t mod = 1e9 + 7;
    f[0][0] = g[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
      g[i][0] = 1;
      int p =
          upper_bound(pos.begin(), pos.end(), pos[i] - mi) - pos.begin() - 1;
      for (int j = 1; j <= min(i, k - 1); ++j) {
        f[i][j] = g[p][j - 1];
        g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
      }
    }
    return g[m][k - 1];
  }
};
