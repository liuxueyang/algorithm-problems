#include "../template.hpp"

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

// set y to left child of x
template< class T >
void set_left( Bstp< T > x, Bstp< T > y )
{
  x->left = y;
  if ( y ) y->parent = x;
}

// set y to right child of x
template< class T >
void set_right( Bstp< T > x, Bstp< T > y )
{
  x->right = y;
  if ( y ) y->parent = x;
}

// set l and r to children of x
template< class T >
void set_children( Bstp< T > x, Bstp< T > l, Bstp< T > r)
{
  set_left( x, l );
  set_right( x, r );
}

// replace x with y
template< class T >
void replace( Bstp< T > x, Bstp< T > y )
{
  Bstp< T > parent = x->parent;

  if ( ! parent ) {
    if ( y ) y->parent = nullptr;
  }
  else if ( parent->left == x ) {
    set_left( parent, y );
  }
  else {
    set_right( parent, y );
  }

  x->parent = nullptr;
}


template< class T >
Bstp< T > left_rotate_bst( Bstp< T > t, Bstp< T > x )
{
  Bstp< T > p = x->parent;
  Bstp< T > y = x->right;
  Bstp< T > a = x->left;

  if ( y ) {
    Bstp< T > b = y->left;
    Bstp< T > c = y->right;

    replace( x, y );
    set_children( x, a, b );
    set_children( y, x, c );

    if ( ! p ) t = y;
  }

  return t;
}

template< class T >
Bstp< T > right_rotate_bst( Bstp< T > t, Bstp< T > y )
{
  Bstp< T > p = y->parent;
  Bstp< T > x = y->left;
  Bstp< T > c = y->right;

  if ( x ) {
    Bstp< T > a = x->left;
    Bstp< T > b = x->right;

    replace( y, x );
    set_children( x, a, y );
    set_children( y, b, c );

    if ( ! p ) t = x;
  }
}


int main( void )
{


  return 0;
}
