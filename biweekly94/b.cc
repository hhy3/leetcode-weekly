#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
 public:
  vector<int> topStudents(vector<string>& positive_feedback,
                          vector<string>& negative_feedback,
                          vector<string>& report, vector<int>& student_id,
                          int k) {
    auto split = [&](const string& s) {
      vector<string> ws;
      for (int i = 0, j = 0; j <= s.size(); ++j) {
        if (j == s.size() || s[j] == ' ') {
          ws.push_back(s.substr(i, j - i));
          i = j + 1;
        }
      }
      return ws;
    };
    set<string> s1(positive_feedback.begin(), positive_feedback.end());
    set<string> s2(negative_feedback.begin(), negative_feedback.end());
    vector<pair<int, int>> a;
    for (int i = 0; i < report.size(); ++i) {
      int cnt = 0;
      for (auto&& w : split(report[i])) {
        if (s1.count(w)) cnt += 3;
        if (s2.count(w)) cnt -= 1;
      }
      a.push_back({-cnt, student_id[i]});
    }
    sort(a.begin(), a.end());
    vector<int> ans(k);
    for (int i = 0; i < k; ++i) ans[i] = a[i].second;
    return ans;
  }
};
