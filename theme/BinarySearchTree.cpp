/*
  Date: 2018/04/24
*/

// ==================================================

#include "../template.hpp"

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
    // before delete it if necessary!
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
