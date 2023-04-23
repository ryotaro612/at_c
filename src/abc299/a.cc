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
  string s;
  cin >> n >> s;
  int bar = 0;
  rep(i, s.size()) {
    if (s[i] == '|')
      bar++;
    else if (s[i] == '*' && bar == 1) {
      cout << "in" << endl;
      return 0;
    }
  }
  cout << "out" << endl;
  return 0;
}
#endif
