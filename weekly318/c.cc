#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long totalCost(vector<int> &a, int x, int k) {
    int n = a.size();
    int64_t ans = 0;
    int i = 0, j = n - 1;
    using p = array<int, 3>;
    priority_queue<p, vector<p>, greater<p>> pq;
    for (; i < k; ++i) {
      pq.push({a[i], i, 0});
    }
    for (; j >= n - k && j >= i; --j) {
      pq.push({a[j], j, 1});
    }
    while (x--) {
      auto [val, id, dir] = pq.top();
      pq.pop();
      ans += val;
      if (i <= j) {
        if (dir == 0) {
          pq.push({a[i], i, 0});
          i++;
        } else {
          pq.push({a[j], j, 1});
          j--;
        }
      }
    }
    return ans;
  }
};