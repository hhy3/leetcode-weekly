#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int unequalTriplets(vector<int> &a) {
    int ans = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k]) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};