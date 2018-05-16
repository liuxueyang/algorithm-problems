/*
  Date: 2018/01/25
*/

// ==================================================

// C library
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Containers
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

// Other
#include <tuple>
#include <string>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <random>
#include <chrono>

// ==================================================

using namespace std;

using PII = pair<int, int>;

// ==================================================

static auto __________2333__________ = []() {
  ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

// ==================================================
#define max_(x, y) ((x) > (y) ? (x) : (y))
#define min_(x, y) ((x) > (y) ? (y) : (x))

#define PR(x) cout << #x " = " << (x) << "\t"
#define NL cout << "\n"

#define PRINT1(x) PR(x), NL
#define PRINT2(x1, x2) PR(x1), PRINT1(x2)
#define PRINT3(x1, x2, x3) PR(x1), PRINT2(x2, x3)
#define PRINT4(x1, x2, x3, x4) PR(x1), PRINT3(x2, x3, x4)

// ==================================================

template<typename T>
void PRINTC(const T& a) { cout << a << " "; }

template<typename T>
void PRINT_CONTAINER(const T& c) { for (auto x : c) PRINTC(x); NL; }

template<typename T>
void PRINTV(const vector<T>& c) { PRINT_CONTAINER<vector<T>>(c); }

template<typename T>
void PRINTA(const T ar[], int n) {
  for (int i = 0; i < n; ++i) PRINTC(ar[i]); NL;
}

template<typename T1, typename T2>
void PRINTP(const pair<T1, T2>& p) { PRINTC(p.first); PRINTLN(p.second); }

template<typename T>
void PRINTLN(const T& a) { cout << a << "\n"; }

template< typename T1, typename T2 >
void PRINTAV( T1 & vec, T2 x) {
  ostream_iterator< T2 > O( cout, " " );
  copy( begin( vec ), end( vec ), O ); NL;
}

// ==================================================


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
