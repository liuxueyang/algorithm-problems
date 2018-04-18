// Date: Wed Apr 18 23:09:59 CST 2018

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
using ll = long long;

const int SZ = 100000;
string sq[ SZ + 1 ];

int cmpcnt( string square, string n )
{
  size_t i = 0;
  int cnt = 0;
  
  for ( auto x : square ) {
    for ( ; i < n.size(); ) {
      if ( n[ i++ ] == x ) {
	cnt++;
	break;
      }
    }
  }

  return cnt == int( square.size() ) ? ( n.size() - cnt ) : -1;
}


int main(void) {

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  for ( ll i = 1; i <= SZ; ++i ) sq[ i ] = to_string( i * i );

  string n;
  
  while ( cin >> n ) {
    int r = -1;
    int x;
    
    for ( auto i = 1; i <= SZ; ++i ) {
      x = cmpcnt( sq[ i ], n );

      if ( x != -1 ) {
  	if ( -1 == r ) r = x;
  	else r = min_( r, x );
      }
    }

    PRINTLN( r );
  }

  return 0;
}
