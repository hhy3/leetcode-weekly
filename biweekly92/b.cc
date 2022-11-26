#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &a) {
    int m = a.size(), n = a[0].size();
    vector<int> col(m), row(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j]) {
          col[i]++, row[j]++;
        }
      }
    }
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = 2 * (col[i] + row[j]) - m - n;
      }
    }
    return ans;
  }
};