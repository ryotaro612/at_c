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
  int n;
  string s;
  cin >> n >> s;
  int n_t = 0, n_a = 0;
  rep(i, n) {
    if (s[i] == 'T')
      n_t++;
    else
      n_a++;
  }
  if (n_t > n_a) {
    cout << "T\n";
    return 0;
  } else if (n_a > n_t) {
    cout << "A\n";
    return 0;
  }

  int i_t = 0, i_a = 0;
  for (auto c : s) {
    if (c == 'T') {
      i_t++;
    } else {
      i_a++;
    }
    if (i_t == n_t) {
      cout << "T\n";
      return 0;
    } else if (i_a == n_a) {
      cout << "A\n";
      return 0;
    }
  }
  return 0;
}
// #endif
