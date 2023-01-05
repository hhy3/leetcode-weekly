#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int maximumTastiness(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    int lo = 0, hi = 1e9;
    while (lo < hi) {
      int mid = lo + hi + 1 >> 1;
      int cnt = 1, pre = a[0];
      for (int i = 1; i < n; ++i) {
        if (a[i] - pre >= mid) {
          cnt++, pre = a[i];
        }
      }
      if (cnt >= k) lo = mid;
      else hi = mid - 1;
    }
    return lo;
  }
};