#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubarrays(vector<int> &a, int k) {
    int n = a.size();
    int p = find(a.begin(), a.end(), k) - a.begin();
    vector<int> b(n);
    b[p] = 0;
    for (int i = p - 1; i >= 0; --i) {
      if (a[i] < k) {
        b[i] = b[i + 1] - 1;
      } else {
        b[i] = b[i + 1] + 1;
      }
    }
    for (int i = p + 1; i < n; ++i) {
      if (a[i] < k) {
        b[i] = b[i - 1] - 1;
      } else {
        b[i] = b[i - 1] + 1;
      }
    }
    map<int, int> cnt;
    for (int i = p; i < n; ++i) {
      cnt[b[i]]++;
    }
    int ans = 0;
    for (int i = 0; i <= p; ++i) {
      ans += cnt[-b[i]] + cnt[-b[i] + 1];
    }
    return ans;
  }
};