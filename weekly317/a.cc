#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int averageValue(vector<int> &a) {
    int sum = 0, cnt = 0;
    for (auto &x : a) {
      if (x % 6 == 0) {
        sum += x;
        cnt++;
      }
    }
    return cnt ? sum / cnt : 0;
  }
};