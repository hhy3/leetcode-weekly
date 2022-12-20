#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
    vector<int> ans;
    ans.reserve(q.size());
    for (auto& qq : q) {
      int u = qq[0], v = qq[1];
      if (u > v) swap(u, v);
      int d = __builtin_clz(u) - __builtin_clz(v);
      v >>= d;
      if (u == v)
        ans.push_back(d + 1);
      else
        ans.push_back(d + 1 + 2 * (32 - __builtin_clz(u ^ v)));
    }
    return ans;
  }
};