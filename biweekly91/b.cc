#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    constexpr int64_t mod = 1e9 + 7;
    vector<int64_t> f(high + 1);
    f[0] = 1;
    int64_t ans = 0;
    for (int i = 1; i <= high; ++i) {
      if (i >= zero) {
        f[i] += f[i - zero];
      }
      if (i >= one) {
        f[i] += f[i - one];
      }
      f[i] %= mod;
      if (i >= low) {
        ans = (ans + f[i]) % mod;
      }
    }
    return ans;
  }
};