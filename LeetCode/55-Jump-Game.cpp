#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;

    int cur = 0;
    int pos = cur + nums[0];

    while (cur <= pos && cur < nums.size()) {
      pos = max(cur + nums[cur], pos);
      cur++;
    }

    return pos >= nums.size() - 1;
  }
};

int main(void) {
  Solution a;

  vector<int> a_ { 2,3,1,1,4 };
  cout << a.canJump(a_) << endl;

  vector<int> b_ { 3,2,1,0,4 };
  cout << a.canJump(b_) << endl;

  vector<int> c_ { 1,2,3 };
  cout << a.canJump(c_) << endl;

  return 0;
}
