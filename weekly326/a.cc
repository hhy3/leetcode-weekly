#include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 42;
}();

class Solution {
public:
    int countDigits(int x) {
       int ans = 0;
       for (int X = x; X; X /= 10) {
         if (x % (X % 10) == 0) ans++; 
       } 
       return ans;
    }
};