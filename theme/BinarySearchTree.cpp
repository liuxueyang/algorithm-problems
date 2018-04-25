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
    else return old_root;
  }

  if ( parent->key > k ) parent->left = leaf; // bug!
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

template< class T >
Bstp< T > lookup_node( Bstp< T > root, T k )
{
  while ( root && root->key != k ) {
    if ( root->key > k ) root = root->left;
    else root = root->right;
  }

  return root;
}

template< class T >
Bstp< T > min_node( Bstp< T > root )
{
  if ( ! root )
    return root;

  while ( root->left ) root = root->left;

  return root;
}

template< class T >
Bstp< T > max_node( Bstp< T > root )
{
  if ( ! root ) return root;

  while ( root->right ) root = root->right;

  return root;
}

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

template< class T >
Bstp< T > delete_node( Bstp< T > root, Bstp< T > x )
{
  if ( ! x ) return root;

  Bstp< T > parent = x->parent;
  Bstp< T > x1 = x;

  if ( ! x->left ) x = x->right;
  else if ( ! x->right ) x = x->left;
  else {
    Bstp< T > y = min_node( x->right ); // y doesn't have left child

    x->key = y->key;

    if ( x == y->parent ) x->right = y->right;
    else y->parent->left = y->right;

    if ( y->right ) y->right->parent = y->parent;

    delete y;

    return root;
  }

  if ( parent ) {
    // set parent
    if ( parent->left == x1 ) parent->left = x;
    else parent->right = x;
  }

  if ( x ) x->parent = parent;
  delete x1;

  return root;
}

using bsti = Bst< int >;
using bstip = Bst< int > *;

int main( void ) {
  bsti tree { 3 };

  insert_node( & tree, 4 );
  insert_node( & tree, 2 );
  insert_node( & tree, 5 );

  in_order_walk( & tree );

  NL;

  return 0;
}
