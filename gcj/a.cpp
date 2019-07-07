#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

string normal(string s) {
  string r;
  int i = 0;
  while (i < int(s.size()) && s[i] == '0') ++i;
  return s.substr(i);
}

int main() {
  int T;
  #ifdef DEBUG
  freopen("a.in", "r", stdin);
  #endif
  cin >> T;
  string s;

  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    cin >> s;
    string r1(s.size(), '0'), r2(s.size(), '0');
    for (int i = 0; i < int(s.size()); ++i) {
      if (s[i] == '4') {
        r1[i] = r2[i] = '2';
      } else {
        r1[i] = s[i];
        r2[i] = '0';
      }
    }
    cout << normal(r1) << " " << normal(r2) << endl;
  }

  return 0;
}
