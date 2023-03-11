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
  string s;
  cin >> s;
  for (int i = 1; i <= as_int(s.size()) / 2; i++) {
    swap(s[i * 2 - 1 - 1], s[i * 2 - 1]);
  }
  cout << s << endl;
  return 0;
}
#endif
