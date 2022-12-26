#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int captureForts(vector<int>& a) {
    int n = a.size(), ans = 0;
    auto find = [&] (int i, int d) {
      while (i >= 0 && i < n && a[i] == 0) {
        i += d;
      }
      if (i >= 0 && i < n && a[i] == -1) {
        return i;
      } else {
        return -1;
      }
    };
    for (int i = 0; i < n; ++i) if (a[i] == 1) {
      int l = find(i - 1, -1), r = find(i + 1, 1); 
      if (l != -1) ans = max(ans, i - l - 1);
      if (r != -1) ans = max(ans, r - i - 1);
    }
    return ans;
  }
};
