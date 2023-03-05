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
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];

  int res = 0;
  rep(i, n) {
    int last = -1;
    rep(j, n) if (sv[i][j] == '.') last = j;
    if (last == -1)
      continue;
    res++;
    if (i < n - 1) {
      for (int j = last; j < n; j++)
        sv[i + 1][j] = 'o';
    }
  }
  cout << res << endl;
  return 0;
}
#endif
