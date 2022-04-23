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
  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;

  int takahashi = (x / (a + c)) * (b * a);
  int amari = x % (a + c);
  takahashi += min(amari, a) * b;
  // cout << "takaha" << takahashi << endl;
  int aoki = (x / (d + f)) * (e * d);
  int ao_amari = x % (d + f);
  aoki += min(ao_amari, d) * e;
  // cout << "aoki" << aoki << endl;
  if (aoki < takahashi)
    cout << "Takahashi" << endl;
  else if (aoki == takahashi) {
    cout << "Draw" << endl;
  } else
    cout << "Aoki" << endl;

  return 0;
}
#endif
