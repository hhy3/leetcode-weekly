#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        int mi = INT_MAX;
        vector<vector<pair<int, int>>> G(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            u--, v--;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        vector<bool> visited(n);
        function<void(int)> dfs = [&] (int u) {
            visited[u] = true;
            for (auto [v, w] : G[u]) {
                mi = min(mi, w);
                if (!visited[v]) {
                    dfs(v);
                }
            }
        };
        dfs(0);
        return mi;
    }
};