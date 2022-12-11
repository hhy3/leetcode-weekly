#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxJump(vector<int> &a) {
    int n = a.size();
    int ans = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
      ans = max(ans, a[i] - a[i - 2]);
    }
    return ans;
  }
};
