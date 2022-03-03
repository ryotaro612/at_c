#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  int i = 0;
  // cout << s << endl;
  for (auto c : s) {
    if (c == 'o')
      i++;
  }

  cout << 700 + 100 * i << endl;
  return 0;
}
#endif
