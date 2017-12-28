#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int len = (int) nums.size();

    for (auto i = 0; i < len; ++i) {
      while (nums[i] != len && i != nums[i]) {
	swap(nums[i], nums[nums[i]]);
      }
    }

    for (auto i = 0; i < len; ++i) {
      if (i != nums[i]) return i;
    }

    return len;
  }
};
