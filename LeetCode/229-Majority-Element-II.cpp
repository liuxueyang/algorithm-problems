#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;

    if (nums.size() == 0) return result;
    
    int cnt1 = 0, cnt2 = 0, re1 = 0, re2 = 0;

    for (auto x : nums) {
      if (cnt1 == 0) {
	cnt1++;
	re1 = x;
      }
      else if (cnt2 == 0) {
	cnt2++;
	re2 = x;
      }
      else if (x == re1) {
	cnt1++;
      }
      else if (x == re2) {
	cnt2++;
      }
      else if (cnt1 <= cnt2) {
	cnt1--;
      }
      else if (cnt2 < cnt1 ) {
	cnt2--;
      }
    }

    vector<int> result {re1, re2};

    return result;
  }
  
  vector<int> majorityElement_naive(vector<int>& nums) {
    unordered_map<int, int> s;
    set<int> se;
    vector<int> result;
    auto len = nums.size() / 3;

    for (auto x : nums) {
      s[x]++;
	
      if (s[x] > len && se.find(x) == se.end()) {
	result.push_back(x);
	se.insert(x);
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
