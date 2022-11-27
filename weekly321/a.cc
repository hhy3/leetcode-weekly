#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int pivotInteger(int n) {
    for (int i = 1; i <= n; ++i) {
      if (i * (i + 1) * 2 - 2 * i == n * (n + 1)) {
        return i;
      }
    }
    return -1;
  }
};