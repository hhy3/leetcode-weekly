#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> applyOperations(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == a[i + 1]) {
        a[i] *= 2;
        a[i + 1] = 0;
      }
    }
    for (int i = 0, j = 0; j < n; ++j) {
      if (a[j] != 0) {
        swap(a[i++], a[j]);
      }
    }
    return a;
  }
};