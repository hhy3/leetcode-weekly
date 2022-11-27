#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    vector<int> a, b;
    for (auto p = head; p; p = p->next) {
      b.push_back(p->val);
    }
    int mx = 0;
    for (int i = b.size() - 1; i >= 0; --i) {
      if (b[i] >= mx) {
        mx = b[i];
        a.push_back(mx);
      }
    }
    ListNode *ans = new ListNode();
    auto cur = ans;
    for (int i = a.size() - 1; i >= 0; --i) {
      cur->next = new ListNode(a[i]);
      cur = cur->next;
    }
    return ans->next;
  }
};