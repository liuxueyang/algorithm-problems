#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int cnt = 0, result = 0;

    for (auto x : nums) {
      if (cnt == 0) {
	result = x;
	cnt++;
      }
      else if (x == result) {
	cnt++;
      }
      else {
	cnt--;
      }
    }

    return result;
  }

  int majorityElement_naive(vector<int>& nums) {
    unordered_map<int, int> m;
    auto s = nums.size() / 2;
    int result = 0;

    for (auto x : nums) {
      m[x]++;

      if (m[x] > s) {
	result = x;
	break;
      }
    }

    return result;
  }
};

int main(void) {
  Solution a;

  vector<int> b {3, 2, 2};

  cout << a.majorityElement(b) << endl;

  return 0;
}
