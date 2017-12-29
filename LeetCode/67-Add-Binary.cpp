#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    if (a == "0") return b;
    else if (b == "0") return a;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result;
    int acc = 0;
    int lena = int(a.length()), lenb = int(b.length());
    int tmp, res;

    for (auto i = 0; i < min(lena, lenb); ++i) {
      tmp = a[i] - '0' + b[i] - '0' + acc;
      acc = tmp / 2;
      res = tmp % 2;
      result += (res == 0 ? "0" : "1");
    }

    string c = a;
    int len = lena;

    if (lena < lenb) {
      c = b;
      len = lenb;
    }

    for (auto i = lena + lenb - len; i < len; ++i) {
      tmp = c[i] - '0' + acc; acc = tmp / 2; res = tmp % 2;
      result += (res == 0 ? "0" : "1");
    }

    if (acc) result += "1";

    reverse(result.begin(), result.end());

    return result;
  }
};

int main(void) {
  Solution a;

  cout << a.addBinary("11", "1") << endl;
  cout << a.addBinary("101", "1") << endl;
  cout << a.addBinary("11", "11") << endl;

  return 0;
}
