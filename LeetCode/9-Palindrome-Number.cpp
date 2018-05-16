#include "../template.hpp"

class Solution {
public:
  bool isPalindrome(int x) {
    if ( x < 0 ||
	 ( x && ( x % 10 == 0 ) ) ) return false;

    int sum = 0;

    while ( sum < x ) {
      sum = sum * 10 + x % 10;
      x /= 10;
    }

    return ( sum == x ) || ( sum / 10 == x );
  }
};

int main( void ) {

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  Solution a;
  vector< int > test = {
    121,
    -121,
    10
  };

  for ( auto x : test ) {
    PRINTLN( a.isPalindrome( x ) );
  }

  return 0;
}
