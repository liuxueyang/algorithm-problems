#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
  #ifdef DEBUG
  freopen("b.in", "r", stdin);
  #endif

  int T, n;
  cin >> T;

  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    string s, r;
    cin >> n >> s;
    for (auto c : s) r += (c == 'E' ? 'S' : 'E');
    cout << r << endl;
  }

  return 0;
}
