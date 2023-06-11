#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  map<char, int> d;
  d['A'] = 0;
  d['B'] = 3;
  d['C'] = 4;
  d['D'] = 8;
  d['E'] = 9;
  d['F'] = 14;
  d['G'] = 23;
  char p, q;
  cin >> p >> q;
  cout << abs(d[p] - d[q]) << endl;

  return 0;
}
#endif
