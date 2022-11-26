#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int bestClosingTime(string s) {
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      a[i] = a[i - 1] + (s[i - 1] == 'Y');
    }
    int mx = a[n];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x = (i - a[i]) + (a[n] - a[i]);
      if (x < mx) {
        mx = x;
        ans = i;
      }
    }
    return ans;
  }
};