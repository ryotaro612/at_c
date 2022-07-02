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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int head = 0;
  rep(i, q) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      head = (head - x + n) % n;
    } else {
      cout << s[(head + (x - 1)) % n] << endl;
    }
  }
  return 0;
}
#endif
