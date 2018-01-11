#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    set<ListNode *> s;

    while (head != NULL) {
      if (s.find(head) != s.end()) return true;
      s.insert(head);
      head = head->next;
    }

    return false;
  }
};

int main(void) {
  Solution a;

  vector<int> b {3, 2, 2};

  cout << a.majorityElement(b) << endl;

  return 0;
}
