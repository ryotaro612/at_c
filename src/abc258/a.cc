#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int k;
  cin >> k;

  if (k < 60) {
    string s = to_string(k);
    if (k < 10) {
      s = "0" + s;
    }
    cout << "21:" << s << endl;
  } else {
    k -= 60;
    string s = to_string(k);
    if (k < 10) {
      s = "0" + s;
    }
    cout << "22:" << s << endl;
  }
  return 0;
}
#endif
