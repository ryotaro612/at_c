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
  string s, t;
  cin >> n >> s >> t;
  int diff = 0;
  rep(i, n) {
    if (s[i] != t[i])
      diff++;
  }
  if (diff % 2) {
    cout << -1 << endl;
    return 0;
  }
  int sd = 0, td = 0;

  rep(i, n) {
    if (s[i] == t[i])
      cout << "0";
    else {
      diff--;
      if (abs(sd - td) <= diff) {
        cout << "0";
        if (s[i] == '0') {
          td++;
        } else
          sd++;
      } else { // diff < abs(sd-td)
        if (sd < td) {
          cout << t[i];
          sd++;
        } else {
          cout << s[i];
          td++;
        }
      }
    }
  }

  cout << endl;

  return 0;
}
#endif
