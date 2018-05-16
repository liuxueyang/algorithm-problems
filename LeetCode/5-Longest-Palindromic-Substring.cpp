#include "../template.hpp"

class Solution {
public:
  string longestPalindrome(string s) {
    if ( s.size() == 0 || s.size() == 1 ) return s;

    int i, j, k, max_len { 1 }, start { 0 }, tmp_len;
    int len = static_cast< int >( s.size() );

    for ( i = 0; i < len; ) {
      j = k = i;
      while ( k < len - 1 && s[ k ] == s[ k + 1 ] ) ++k;
      i = k + 1;
      while ( j - 1 >= 0 && k + 1 < len &&
	      s[ j - 1 ] == s[ k + 1 ] ) {
	--j;
	++k;
      }

      tmp_len = k - j + 1;

      if ( tmp_len > max_len ) {
	start = j;
	max_len = tmp_len;
      }
    }

    return s.substr( start, max_len );
  }
};

int main( void ) {

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  Solution a;
  vector< string > vs = {
    "babad",
    "cbbd",
  };

  for ( auto s : vs ) {
    PRINTLN( a.longestPalindrome( s ) );
  }


  return 0;
}
