#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

std::vector<int> prime_sieve(int n, std::vector<int> &sieve) {
  sieve.resize(n + 1);
  std::vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    if (!sieve[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > n) break;
      sieve[i * p] = p;
      if (i % p == 0) break;
    }
  }
  return primes;
}

class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> t;
    auto p = prime_sieve(right, t);
    vector<int> ans;
    int pre = -1;
    for (auto x : p) {
      if (pre >= left && (ans.empty() || x - pre < ans[1] - ans[0])) {
        ans = {pre, x};
      }
      pre = x;
    }
    if (ans.empty()) ans = {-1, -1};
    return ans;
  }
};