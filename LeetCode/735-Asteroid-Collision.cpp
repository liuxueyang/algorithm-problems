#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
  void validate(stack<int>& s) {
    if (s.size() <= 1) {
      return;
    }

    while (s.size() > 1) {
      int t = s.top();
      s.pop();

      if (t * s.top() > 0 || (t > 0 && s.top() < 0)) {
	s.push(t);
	break;
      }
      else {
	int t1 = s.top();
	s.pop();

	if (abs(t1) > abs(t)) {
	  s.push(t1);
	}
	else if (abs(t1) < abs(t)) {
	  s.push(t);
	}
      }
    }
  }

  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;

    for (auto x : asteroids) {
      s.push(x);
      validate(s);
    }

    vector<int> result(s.size());

    for (auto i = s.size() - 1; !s.empty(); --i) {
      result[i] = s.top();
      s.pop();
    }

    return result;
  }
};

void print_vec(const vector<int>& v) {
  for (auto x : v) {
    cout << x << " ";
  }

  cout << endl;
}

int main(void) {
  Solution a;

  vector<int> as1 {5, 10, -5};
  vector<int> as2 {8, -8};
  vector<int> as3 {10, 2, -5};
  vector<int> as4 {-2, -1, 1, 2};

  print_vec(a.asteroidCollision(as1));
  print_vec(a.asteroidCollision(as2));
  print_vec(a.asteroidCollision(as3));
  print_vec(a.asteroidCollision(as4));

  return 0;
}
