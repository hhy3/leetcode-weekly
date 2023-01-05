#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int takeCharacters(string s, int k) {
    int n = s.size();
    s = " " + s;
    vector<array<int, 3>> b(n + 1);
    for (int i = 1; i <= n; ++i) {
      b[i] = b[i - 1];
      b[i][s[i] - 'a']++;
    }
    if (b[n][0] < k || b[n][1] < k || b[n][2] < k) return -1;
    int ans = 1e9;
    for (int i = 0; i <= n; ++i) {
      int lo = 0, hi = n;
      while (lo < hi) {
        int mid = lo + hi + 1 >> 1;
        bool ok = true;
        for (int j = 0; j < 3; ++j) {
          if (b[n][j] - b[mid][j] + b[i][j] < k) ok = false;
        }
        if (ok) lo = mid;
        else hi = mid - 1;
      }
      ans = min(ans, i + n - lo);
    }
    return ans;
  }
};