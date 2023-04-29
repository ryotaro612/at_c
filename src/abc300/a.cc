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

// #ifdef ONLINE_JUDGE
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  rep(i, n) {
    int c;
    cin >> c;
    if (c == a + b) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
// #endif
