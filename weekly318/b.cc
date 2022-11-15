#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int> &a, int k) {
    map<int, int> mp;
    int n = a.size();
    vector<int64_t> b(n + 1);
    for (int i = 1; i <= n; ++i) {
      b[i] = b[i - 1] + a[i - 1];
    }
    for (int i = 0; i < k; ++i) {
      mp[a[i]]++;
    }
    int64_t ans = 0;
    if (mp.size() == k) {
      ans = b[k];
    }
    for (int i = k; i < n; ++i) {
      mp[a[i]]++;
      if (--mp[a[i - k]] == 0) {
        mp.erase(a[i - k]);
      }
      if (mp.size() == k) {
        ans = max(ans, b[i + 1] - b[i - k + 1]);
      }
    }
    return ans;
  }
};