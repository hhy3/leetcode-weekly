#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> splitMessage(string s, int K) {
    int n = s.size();
    vector<int> f(n + 1, 1);
    for (int i = 10; i <= n; ++i) {
      f[i] = f[i / 10] + 1;
    }

    auto check = [&](int x) -> bool {
      int tot = 0;
      for (int i = 1, j = 10; i < x; i *= 10, j *= 10) {
        int each = K - 3 - f[x] - f[i];
        tot += each * (min(j, x) - i);
      }
      if (n - tot > 0 && n - tot <= K - 3 - f[x] - f[x]) {
        return true;
      }
      return false;
    };

    auto gen = [&](int x) -> vector<string> {
      vector<string> ans;
      int tot = 0;
      auto push = [&](int i, int pos, int len) {
        ans.push_back(s.substr(pos, len) + "<" + to_string(i) + "/" +
                      to_string(x) + ">");
      };
      for (int i = 1; i < x; ++i) {
        int each = K - 3 - f[x] - f[i];
        push(i, tot, each);
        tot += each;
      }
      push(x, tot, n - tot);
      return ans;
    };

    for (int x = 1; x <= n; ++x) {
      if (check(x)) {
        return gen(x);
      }
    }
    return {};
  }
};