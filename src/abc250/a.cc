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
  int h, w, r, c;
  cin >> h >> w >> r >> c;
  r--;
  c--;
  int res = 0;
  if (0 < r)
    res++;
  if (c < w - 1)
    res++;
  if (r < h - 1)
    res++;
  if (0 < c)
    res++;
  cout << res << endl;
  return 0;
}
#endif
