#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumValue(vector<string> &a) {
    int ans = 0;
    for (auto &s : a) {
      if (all_of(s.begin(), s.end(),
                 [](auto c) { return c >= '0' && c <= '9'; })) {
        ans = max(ans, (int)stoll(s));
      } else {
        ans = max(ans, (int)s.size());
      }
    }
    return ans;
  }
};