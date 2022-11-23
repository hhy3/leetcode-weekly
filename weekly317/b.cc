
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> mostPopularCreator(vector<string> &creators,
                                            vector<string> &ids,
                                            vector<int> &views) {
    vector<vector<string>> ans;
    map<string, int64_t> sum, mx;
    map<string, string> mp;
    int n = creators.size();
    for (int i = 0; i < n; ++i) {
      sum[creators[i]] += views[i];
      if (!mx.count(creators[i]) || views[i] > mx[creators[i]])
        mp[creators[i]] = ids[i], mx[creators[i]] = views[i];
      else if (views[i] == mx[creators[i]] && ids[i] < mp[creators[i]])
        mp[creators[i]] = ids[i];
    }
    int m = 0;
    for (auto [k, v] : sum) {
      if (v > m) {
        ans = {{k, mp[k]}};
        m = v;
      } else if (v == m) {
        ans.push_back({k, mp[k]});
      }
    }
    return ans;
  }
};