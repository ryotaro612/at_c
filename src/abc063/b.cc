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
  string s;
  cin >> s;
  set<char> ss(s.begin(), s.end());
  if (s.size() == ss.size())
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
#endif
