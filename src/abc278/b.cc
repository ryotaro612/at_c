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
  int h, m;
  cin >> h >> m;
  int time = h * 60 + m;

  while (true) {
    h = time / 60;
    m = time % 60;

    int swap_h = h / 10 * 10 + m / 10;
    int swap_m = h % 10 * 10 + m % 10;

    if (swap_h <= 23 && swap_m <= 59) {
      cout << h << " " << m << endl;
      // cout << swap_h << " " << swap_m << endl;
      break;
    }

    time++;
    if (24 * 60 <= time)
      time = 0;
  }

  return 0;
}
#endif
