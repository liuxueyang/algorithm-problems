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
void set_left( Bstp x, Bstp y )
{
  x->left = y;
  if ( y ) y->parent = x;
}

// set y to right child of x
template< class T >
void set_right( Bstp x, Bstp y )
{
  x->right = y;
  if ( y ) y->parent = x;
}

// set l and r to children of x
template< class T >
void set_children( Bstp x, Bstp l, Bstp r)
{
  set_left( x, l );
  set_right( x, r );
}

template< class T >
void replace( Bstp x, Bstp y )
{
  Bstp parent = x->parent;

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
Bstp left_rotate_bst( Bstp t, Bstp x )
{
  Bstp p = x->parent;
  Bstp y = x->right;
  Bstp a = x->left;

  if ( y ) {
    Bstp b = y->left;
    Bstp c = y->right;

    replace( x, y );
    set_children( x, a, b );
    set_children( y, x, c );

    if ( ! p ) t = y;
  }

  return t;
}

template< class T >
Bstp right_rotate_bst( Bstp t, Bstp y )
{
  Bstp p = y->parent;
  Bstp x = y->left;
  Bstp c = y->right;

  if ( x ) {
    Bstp a = x->left;
    Bstp b = x->right;
    
    replace( y, x );
    set_children( x, a, y );
    set_children( y, b, c );

    if ( ! p ) t = x;
  }
}


int main( void )
{

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif



  return 0;
}
