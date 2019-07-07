#include "../template.hpp"

enum Color {
  Red,
  Black
};

template< class T >
class RedBlackTree {
  using rbt = RedBlackTree< T >;

public:
  RedBlackTree( T x )
    : left ( nullptr ), right ( nullptr ),
      parent ( nullptr ), key ( x ) {}

  ~RedBlackTree()
  {
    // take care when delete a pointer whose
    // child is not NULL! Assign them to nullptr
    // before delete it if necessary!
    delete left;
    delete right;
  };

  Color color;
  Bst * left;
  Bst * right;
  Bst * parent;
  T key;
};

template < class T >
using rbt = RedBlackTree< T >;

template< class T >
using rbtp = RedBlackTree< T > *;


/*
1. parent is leaf: 
*/
template< class T >
void insert( rbtp< T > t, rbtp< T > x )
{
  
}

int main( void )
{
  
  return 0;
}
