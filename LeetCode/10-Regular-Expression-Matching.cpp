#include "../template.hpp"

class Solution {
public:
  string S, P;
  int lens, lenp;
  
  bool isMatch(string s, string p) {
    S = s; P = p;
    lens = static_cast< int >( S.size() );
    lenp = static_cast< int >( P.size() );

    return is_match( 0, 0 );
  }

  bool is_match( int i, int j ) {
    PRINT2( i, j );
    int tmp;
    cin>>tmp;
    if ( i == lens ) {
      return j == lenp;
    }
    if ( j == lenp ) {
      PRINT2( j, lenp );
      getchar();
      return i == lens;
    }
    
    if ( j + 1 < lenp && P[ j + 1 ] != '*' )
      return ( ( ( S[ i ] == P[ j ] ) ||
		 ( P[ j ] == '.' ) ) &&
	       is_match( i + 1, j + 1 ) );

    if ( j < lenp && i < lens &&
	 ( P[ j ] == S[ i ] || P[ j ] == '.' ) ) {
      if ( is_match( i, j + 2 ) ) return true;
      i++;
      PRINT3( i, j, lenp);
    }

    return is_match( i, j + 2 );
  }
};

int main( void ) {

#ifndef ONLINE_JUDGE
  // freopen("in", "r", stdin);
#endif

  Solution a;

  vector< string > vs = {
    "aa", "a",
    // "aa", "a*",
  };

  for ( size_t i = 0; i < vs.size(); i += 2 ) {
    PRINT1( a.isMatch( vs[ i ], vs[ i + 1 ] ) );
  }

  return 0;
}
