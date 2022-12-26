#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int minimizeSet(int x, int y, int c1, int c2) {
    int64_t lo = 0, hi = 1e10;
    while (lo < hi) {
      int64_t mid = lo + hi >> 1;
      int64_t bothdiv = mid / lcm((int64_t)x, (int64_t)y);
      int64_t divx = mid / x;
      int64_t divy = mid / y;
      int64_t c1t = c1, c2t = c2;
      c1t -= min(c1t, divy - bothdiv);
      c2t -= min(c2t, divx - bothdiv);
      if (c1t + c2t <= mid - (divx + divy - bothdiv)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};