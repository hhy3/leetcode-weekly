#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int smallestValue(int n) {
    while (true) {
      int x = 0;
      int tmp = n;
      for (int i = 2; i * i <= tmp; ++i) {
        while (tmp % i == 0) {
          tmp /= i;
          x += i;
        }
      }
      if (tmp > 1) {
        x += tmp;
      }
      if (n == x) {
        return n;
      } else {
        n = x;
      }
    }
    return n;
  }
};