#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    set<int> st;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == target) st.insert(i);
    }
    int ans = -1;
    int n = words.size();
    for (auto x : st) {
      int d = min({abs(startIndex - x), startIndex + n - x,
                   x + n - startIndex});
      if (ans == -1 || d < ans) ans = d;
    }
    return ans;
  }
};