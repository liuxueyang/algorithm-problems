#include "../template.hpp"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
      if ( A.size() > B.size() ) swap( A, B );

      double result { 0.0 };
      int m = static_cast< int > ( A.size() );
      int n = static_cast< int > ( B.size() );

      int i, j, high = m, low = 0, max_left, min_right;

      while ( low <= high ) {
	i = low + ( high - low ) / 2;
	j = ( m + n + 1 ) / 2 - i;

	if ( ( i == 0 || j == n || A[ i - 1 ] <= B[ j ] ) &&
	     ( j == 0 || i == m || B[ j - 1 ] <= A[ i ] ) ) {
	  if ( i == 0 ) max_left = B[ j - 1 ];
	  else if ( j == 0 ) max_left = A[ i - 1 ];
	  else max_left = max_( A[ i - 1 ], B[ j - 1 ] );

	  if ( ( m + n ) & 1 ) result = max_left;
	  else {
	    if ( i == m ) min_right = B[ j ];
	    else if ( j == n ) min_right = A[ i ];
	    else min_right = min_( B[ j ], A[ i ] );

	    result = ( max_left + min_right ) * 1.0 / 2;
	  }

	  break;
	}
	else if ( i > 0 && A[ i - 1 ] > B[ j ] ) {
	  high = i - 1;
	}
	else if ( i < m && B[ j - 1 ] > A[ i ] ) {
	  low = i + 1;
	}
      }

      return result;
    }
};

int main( void ) {

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  Solution a;

  vector< vector< int > > vec_list = {
    { 1, 3 },
    { 2 },
    { 1, 2 },
    { 3, 4 },
    { 2, 2 },
    { 2, 3 },
  };

  for ( size_t i = 0; i < vec_list.size(); i += 2 ) {
    PRINTV( vec_list[ i ] );
    PRINTV( vec_list[ i + 1 ] );
    double result = a.findMedianSortedArrays( vec_list[ i ],
					      vec_list[ i + 1 ] );
    PRINT1( result );
  }

  return 0;
}
