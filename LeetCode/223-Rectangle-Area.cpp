#include <iostream>

using namespace std;

class Point {
public:
  Point(int x, int y)
    : x(x), y(y) { }
  Point(Point &a)
    : x(a.x), y(a.y) {}

  Point& operator=(const Point &other) {
    if (this != &other) {
      this->x = other.x;
      this->y = other.y;
    }

    return *this;
  }

  int x;
  int y;
};

class Rectangle {
public:
  Rectangle(Point lower_left, Point upper_right) {
    this->lower_left = lower_left;
    this->upper_right = upper_right;

    this->width = upper_right.x - lower_left.x;
    this->height = upper_right.y - lower_left.y;

    Point lr(upper_right.x, lower_left.y);
    this->lower_right = lr;

    Point ul(lower_left.x, upper_right.y);
    this->upper_left = ul;
  }

  int inter(Rectangle &other) {
    return 0;
  }

  Point lower_left, lower_right;
  Point upper_left, upper_right;
  int width, height;
};

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    Point la(A, B), ra(C, D), lb(E, F), rb(G, H);
    Rectangle a(la, ra);
    Rectangle b(lb, rb);

    return a.inter(b);
  }
};

int main(void) {
  Solution a;

  cout << a.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;

  return 0;
}
