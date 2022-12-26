#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

namespace hy {

template <uint64_t M> struct modint {
  uint64_t x;

  modint() : modint(0) {}

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value> * = nullptr>
  modint(T x_) {
    if constexpr (std::is_signed<T>::value) {
      x = (x_ % T(M) + T(M)) % T(M);
    } else {
      x = x_ % M;
    }
  }

  modint(const modint &rhs) : x(rhs.x) {}

  modint &operator=(const modint &rhs) {
    x = rhs.x;
    return *this;
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value> * = nullptr>
  operator T() {
    return this->x;
  }

  uint64_t val() { return x; }

  modint &operator++() {
    x = (x + 1) % M;
    return *this;
  }

  modint operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
  }

  modint &operator--() {
    x = (x - 1 + M) % M;
    return *this;
  }

  modint operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
  }

  modint &operator+=(modint rhs) {
    x = (x + rhs.x) % M;
    return *this;
  }

  modint &operator-=(modint rhs) {
    x = (x - rhs.x + M) % M;
    return *this;
  }

  modint &operator*=(modint rhs) {
    x = x * rhs.x % M;
    return *this;
  }

  modint &operator/=(modint rhs) { return *this *= rhs.inv(); }

  modint inv() const {
    int64_t u, v, d = extgcd(int64_t(x), int64_t(M), u, v);
    assert(d == 1);
    return modint(u);
  }

  modint pow(uint64_t b) const {
    modint ret = 1, tmp = *this;
    for (; b; b >>= 1, tmp *= tmp)
      if (b & 1)
        ret *= tmp;
    return ret;
  }

  friend modint operator+(modint lhs, modint rhs) { return modint(lhs) += rhs; }

  friend modint operator-(modint lhs, modint rhs) { return modint(lhs) -= rhs; }

  friend modint operator*(modint lhs, modint rhs) { return modint(lhs) *= rhs; }

  friend modint operator/(modint lhs, modint rhs) { return modint(lhs) /= rhs; }

  friend bool operator==(modint lhs, modint rhs) { return lhs.x == rhs.x; }

  friend bool operator!=(modint lhs, modint rhs) { return lhs.x != rhs.x; }

  friend std::ostream &operator<<(std::ostream &os, const modint &rhs) {
    return os << rhs.x;
  }

  friend std::istream &operator>>(std::istream &is, modint &rhs) {
    return is >> rhs.x;
  }

  template <typename T> static T extgcd(T a, T b, T &x, T &y) {
    if (b == 0)
      return x = 1, y = 0, a;
    T d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
  }
};

} // namespace hy

constexpr int mod = 109 + 7;
using mint = hy::modint<mod>;

class Solution {
 public:
  int countAnagrams(string s) {
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

    mint ans = 1;
    for (auto& w : split(s)) {
      int n = w.size();
      int cnt[26]{};
      for (auto c : w) cnt[c - 'a']++;
      for (int i = 1; i <= n; ++i) ans *= i;
      for (int i = 0; i < 26; ++i) {
        if (cnt[i]) ans /= cnt[i]; 
      }
    }
    return int(ans);
  }
};