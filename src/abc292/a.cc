#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <cctype>
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
  for (auto &c : s)
    c = toupper(c);
  cout << s << endl;
  return 0;
}
#endif
