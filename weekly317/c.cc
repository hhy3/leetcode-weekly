
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long makeIntegerBeautiful(long long n, int K) {
    auto calc = [&](int64_t x) -> int64_t {
      int ans = 0;
      for (; x; x /= 10)
        ans += x % 10;
      return ans;
    };
    int64_t x = 10;
    int64_t N = n;
    for (;;) {
      if (calc(n) <= K) {
        return n - N;
      }
      int64_t y = n % x;
      if (y > 0) {
        n += x - y;
      }
      x *= 10;
    }
  }
};