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
  int n;
  string s;
  cin >> n >> s;
  int n_q = 0;
  rep(i, n) {
    if (s[i] == '"') {
      n_q++;
    } else if (s[i] == ',') {
      if (n_q % 2 == 0) {
        s[i] = '.';
      }
    }
  }
  cout << s << endl;

  return 0;
}
#endif
