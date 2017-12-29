#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n < 2) return 0;
    vector<int> a(n, 0);
    vector<bool> flag(n, true);

    for (auto i = 2; i * i < n; ++i) {
      if (flag[i]) {
	for (auto j = i + i; j < n; j += i) {
	  flag[j] = false;
	}
      }
    }

    int result = 0;

    for (auto i = 2; i < n; ++i) {
      if (flag[i]) {
	result++;
      }
    }

    return result;
  }
};

int main(void) {
  Solution a;
  cout << a.countPrimes(50000) << endl;

  return 0;
}
