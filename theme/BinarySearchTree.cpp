/*
  Date: 2018/04/24
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

template< class T >
class BinarySearchTree {
  using Bst = BinarySearchTree< T >;

public:
  BinarySearchTree( T x )
    : left ( nullptr ), right ( nullptr ),
      parent ( nullptr ), key ( x ) {}

  ~BinarySearchTree()
  {
    // take care when delete a pointer whose
    // child is not NULL! Assign them to nullptr
    // if necessary!
    delete left;
    delete right;
  };

  Bst * left;
  Bst * right;
  Bst * parent;
  T key;
};

template < class T >
using Bst = BinarySearchTree< T >;

template< class T >
using Bstp = BinarySearchTree< T > *;

// template constexp
// template< class T >
// T leftkey( ) {}

// return root of bst
template< class T >
Bstp< T > insert_node( Bstp< T > root, T k )
{
  Bstp< T > old_root = root;
  Bstp< T > parent = root;
  Bstp< T > leaf = new Bst< T > { k };

  if ( ! old_root )
    return leaf;

  while ( root ) {
    parent = root;

    if ( root->key > k ) root = root->left;
    else if ( root->key < k ) root = root->right;
    else return old_root;	// found equal value
  }

  if ( parent->key > k ) parent->left = leaf;
  else parent->right = leaf;

  leaf->parent = parent;

  return old_root;
}

template< class T >
void in_order_walk( Bstp< T > root )
{
  if ( root ) {
    in_order_walk( root->left );
    PRINTC( root->key );
    in_order_walk( root->right );
  }
}

// return pointer to founded node or nullptr
template< class T >
Bstp< T > lookup_node( Bstp< T > root, T k )
{
  while ( root && root->key != k ) {
    if ( root->key > k ) root = root->left;
    else root = root->right;
  }

  return root;
}

// return pointer to min node
template< class T >
Bstp< T > min_node( Bstp< T > root )
{
  if ( ! root ) return root;

  while ( root->left ) root = root->left;

  return root;
}

// return pointer to max node
template< class T >
Bstp< T > max_node( Bstp< T > root )
{
  if ( ! root ) return root;

  while ( root->right ) root = root->right;

  return root;
}

// return pointer to succ node or nullptr
template< class T >
Bstp< T > succ_node( Bstp< T > x )
{
  if ( x->right ) return min_node( x->right );

  Bstp< T > parent = x->parent;

  while ( parent && parent->right == x ) {
    x = parent;
    parent = x->parent;
  }

  return parent;
}

// return pointer to pred node or nullptr
template< class T >
Bstp< T > pred_node( Bstp< T > x )
{
  if ( x->left ) return max_node( x->left );

  Bstp< T > parent = x->parent;

  while ( parent && parent->left == x ) {
    x = parent;
    parent = x->parent;
  }

  return parent;
}

// return pointer to root of bst or nullptr
template< class T >
Bstp< T > delete_node( Bstp< T > root, Bstp< T > x )
{
  if ( ! x ) return root;

  Bstp< T > parent = x->parent;	// could be nullptr
  Bstp< T > x1 = x;

  if ( ! x->left ) x = x->right;
  else if ( ! x->right ) x = x->left;
  else {
    Bstp< T > y = min_node( x->right ); // y does not have left child

    x->key = y->key;

    if ( y == x->right ) x->right = y->right;
    else y->parent->left = y->right;

    if ( y->right ) y->right->parent = y->parent;

    y->left = y->right = nullptr;
    delete y;

    return root;
  }

  if ( parent ) {
    // set parent
    if ( parent->left == x1 ) parent->left = x;
    else parent->right = x;
  }
  else root = x;

  if ( x ) x->parent = parent;

  x1->left = x1->right = nullptr;
  delete x1;

  return root;
}

using bsti = Bst< int >;
using bstip = Bst< int > *;

int main( void ) {
  const int N = 20;
  bstip tree = new bsti { N };	// must use new here!
  vector< int > v( N + 1 );

  for ( int i = 1; i <= N; ++i ) v[ i ] = i;

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  shuffle( v.begin(), v.end(), default_random_engine( seed ) );

  for ( auto x : v ) {
    PRINTC( "inserting " );
    PRINT1( x );
    insert_node( tree, x );
  }

  in_order_walk( tree ); NL;
  bstip ptr, ptr2;

  for ( int i = 1; i <= N / 2; ++i ) {
    PRINTLN( "start of for: " );
    in_order_walk( tree ); NL;

    PRINT2( i, v[ i ] );
    ptr = lookup_node( tree, v[ i ] );

    PRINTC( "current node: " );
    PRINT1( ptr->key );

    ptr2 = succ_node( ptr );
    PRINTC( "succ node: " );
    if ( ptr2 ) PRINT1( ptr2->key );
    else PRINT1( NULL );

    ptr2 = pred_node( ptr );
    PRINTC( "pred note: " );
    if ( ptr2 ) PRINT1( ptr2->key );
    else PRINT1( NULL );

    PRINTC( "deleting" );
    PRINT2( i, v[ i ] );

    tree = delete_node( tree, ptr );
    PRINTLN( "deleted finished" );

    in_order_walk( tree ); NL; NL;
  }

  return 0;
}
