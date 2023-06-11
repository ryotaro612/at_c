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
  int n;
  cin >> n;
  int pos = -1, dist = 100000;

  for (int i = 0; i <= 100; i += 5) {
    if (dist > abs(n - i)) {
      pos = i;
      dist = abs(n - i);
    }
  }
  cout << pos << endl;
  return 0;
}
#endif
