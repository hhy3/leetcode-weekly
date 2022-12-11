#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minimumTotalCost(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int64_t ans = 0;
    int mp[n + 1];
    memset(mp, 0, sizeof(mp));
    int mx = -1, mx_cnt = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
        cnt++;
        ans += i;
        if (auto cur_cnt = ++mp[a[i]]; cur_cnt > mx_cnt) {
          mx_cnt = cur_cnt;
          mx = a[i];
        }
      }
    }
    if (mx_cnt * 2 > cnt) {
      for (int i = 0; i < n && mx_cnt * 2 > cnt; ++i) {
        if (a[i] == b[i] || a[i] == mx || b[i] == mx) {
          continue;
        }
        ans += i;
        cnt++;
      }
    }
    if (mx_cnt * 2 > cnt) {
      return -1;
    }
    return ans;
  }
};
