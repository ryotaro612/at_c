#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  for (auto c : s) {
    if (c == '1')
      cout << '9';
    else if (c == '9')
      cout << '1';
    else
      cout << c;
  }
  cout << endl;
}
#endif
