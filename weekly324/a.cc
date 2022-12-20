#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int similarPairs(vector<string>& a) {
    int n = a.size();
    unordered_map<int, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x = 0;
      for (auto c : a[i]) {
        x |= 1 << (c - 'a');
      }
      ans += cnt[x]++;
    }
    return ans;
  }
};