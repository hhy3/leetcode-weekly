#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int magnificentSets(int n, vector<vector<int>> &edges) {
    vector<vector<int>> G(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      u--, v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    vector<int> visited(n, -1);
    map<int, vector<int>> mp;
    int cur = 0;
    function<bool(int, int)> dfs = [&](int u, int c) {
      visited[u] = c;
      mp[cur].push_back(u);
      for (auto v : G[u]) {
        if (visited[v] == -1) {
          if (!dfs(v, c ^ 1)) {
            return false;
          }
        } else if (visited[v] == c) {
          return false;
        }
      }
      return true;
    };

    for (int i = 0; i < n; ++i) {
      if (visited[i] == -1) {
        if (!dfs(i, 0)) {
          return -1;
        }
        cur++;
      }
    }
    int ans = 0;
    for (auto &[_, vec] : mp) {
      int mx = 0;
      auto bfs = [&](int r) -> int {
        int cur = 0;
        queue<pair<int, int>> q;
        q.push({r, 1});
        unordered_set<int> st;
        st.insert(r);
        while (q.size()) {
          auto [u, d] = q.front();
          q.pop();
          cur = max(cur, d);
          for (auto v : G[u]) {
            if (st.count(v)) {
              continue;
            }
            st.insert(v);
            q.push({v, d + 1});
          }
        }
        return cur;
      };
      for (auto &u : vec) {
        mx = max(mx, bfs(u));
      }
      ans += mx;
    }

    return ans;
  }
};