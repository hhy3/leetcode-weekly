#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 10;
int64_t L[N][10][10], R[N][10][10], cnt[10];

class Solution {
public:
  int countPalindromes(string s) {
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    int n = s.size();
    int64_t mod = 1e9 + 7;
    for (auto &x : s) {
      x -= '0';
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i) {
      memcpy(L[i], L[i - 1], sizeof L[i]);
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          L[i][j][k] = L[i - 1][j][k];
        }
        if (s[i - 1] == j) {
          for (int k = 0; k < 10; ++k) {
            L[i][j][k] += cnt[k];
          }
        }
      }
      cnt[s[i - 1]]++;
    }

    memset(cnt, 0, sizeof cnt);
    for (int i = n; i >= 1; --i) {
      memcpy(R[i], R[i + 1], sizeof R[i]);
      for (int j = 0; j < 10; ++j) {
        if (s[i - 1] == j) {
          for (int k = 0; k < 10; ++k) {
            R[i][j][k] += cnt[k];
          }
        }
      }
      cnt[s[i - 1]]++;
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          ans += L[i - 1][j][k] * R[i + 1][j][k];
          ans %= mod;
        }
      }
    }
    return ans;
  }
};