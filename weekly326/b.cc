#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
      set<int> st;
      for (auto x : nums) {
        for (int i = 2; i * i <= x; ++i) {
          while (x % i == 0) {
            x /= i;
            st.insert(i);
          }
        }
        if (x > 1) st.insert(x);
      }        
      return st.size();
    }
};