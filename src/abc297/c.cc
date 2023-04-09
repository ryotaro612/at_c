#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) {
    string s;
    cin >> s;
    for (int i = 0; i < w;) {
      if (s[i] == '.') {
        i++;
        continue;
      }
      if (i < w - 1 && s[i] == 'T' && s[i + 1] == 'T') {
        s[i] = 'P';
        s[i + 1] = 'C';
        i += 2;
      } else {
        i += 1;
      }
    }
    cout << s << endl;
  }
  return 0;
}
#endif
