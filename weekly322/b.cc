#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long dividePlayers(vector<int> &a) {
    sort(a.begin(), a.end());
    int sum = reduce(a.begin(), a.end());
    int n = a.size();
    int X = sum / (n / 2);
    if (sum % X != 0) {
      return -1;
    }
    int64_t ans = 0;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      if (a[i] + a[j] != X) {
        return -1;
      }
      ans += a[i] * a[j];
    }
    return ans;
  }
};