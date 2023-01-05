#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();
class Solution {
 public:
  int minimumPartition(string s, int K) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n;) {
      if (s[i] - '0' > K) return -1;
      int j = i;
      auto ok = [&](int k) { return stoll(s.substr(i, k - i + 1)) <= K; };
      while (j + 1 < n && ok(j + 1)) j++;

      ans++;
      i = j + 1;
    }
    return ans;
  }
};
