#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  string av = "0000";
  for (int i = 0; i < 3; i++) {
    if (s[i] == '1') {
      av[i + 1] = '1';
    }
  }
  cout << av << endl;

  return 0;
}
#endif
