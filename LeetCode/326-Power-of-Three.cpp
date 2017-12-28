#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    return (n == 3 || n == 1) ? true : ((n % 3 || n < 3) ? false : isPowerOfThree(n / 3));
  }
};
