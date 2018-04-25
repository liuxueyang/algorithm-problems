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
void PRINTC(const T& a) { cout << a << " "; }

template<typename T>
void PRINTLN(const T& a) { cout << a << "\n"; }

template< typename T1, typename T2 >
void PRINTAV( T1 & vec, T2 x) {
  ostream_iterator< T2 > O( cout, " " );
  copy( begin( vec ), end( vec ), O ); NL;
}

// ==================================================


using vi = vector< int >;
using mii = unordered_map< int, int >;
using pii = pair< int, int >;
using ll = long long int;

const int SZ = 150000 + 10;
vector< ll > ar( SZ + 1 );
priority_queue< pii, vector< pii >, greater< pii > > que;
mii cnts;

int main( void ) {

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  int n;

  while ( cin >> n ) {
    for ( int i = 0; i < n; ++i ) {
      cin >> ar[ i ];
      ++cnts[ ar[ i ] ];
    }

    for ( auto & x : cnts ) {
      PRINT2( x.first, x.second );
      que.push( make_pair( x.first, x.second ) );
    }

    while ( !que.empty() ) {
      pii x_c = que.top();

      PRINT2( x_c.first, x_c.second );
      
      que.pop();

      if ( cnts[ x_c.first ] != x_c.second ) continue;

      if ( x_c.second == 1 ) {
	cnts.erase( x_c.first );
      }
      else {
	auto pos1 = lower_bound( ar.begin(), ar.end(), x_c.first );
	
	if ( pos1 != ar.end() ) {
	  *pos1 = LLONG_MAX;
	  
	  auto pos2 = lower_bound( pos1, ar.end(), x_c.first );
	    
	  if ( pos2 != ar.end() ) {
	    *pos2 = *pos2 * 2;

	    PRINT1( *pos2 );

	    cnts[ x_c.first ] -= 2;
	    ++cnts[ *pos2 ];

	    if ( cnts[ x_c.first ] >= 2 )
	      que.push( make_pair( x_c.first, cnts[ x_c.first ] ) );

	    if ( cnts[ *pos2 ] >= 2 )
	      que.push( make_pair( *pos2, cnts[ *pos2 ] ) );
	  }
	}
      }
    }

    for ( int i = 0; i < n; ++i ) {
      if ( ar[ i ] != LLONG_MAX ) {
	PRINTC( ar[ i ] );
      }
    }
    
    NL;
  }

  return 0;
}
