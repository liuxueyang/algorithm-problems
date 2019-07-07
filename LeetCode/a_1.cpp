#include <unordered_map>
#include <vector>
using uii = unordered_map<int,int>;
using vi = vector<int>;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      uii a;
      a[nums[0]]=0;
      vi res;
      for(int i=1;i<int(nums.size()); ++i){
        int t=target-nums[0];
        if (uii.find(t) != uii.end()) {
          return vi{uii[t], i};
        }
        uii[nums[i]]=i;
      }
      return res;
    }
};
