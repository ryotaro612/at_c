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
  string s;
  cin >> s;
  unordered_set<char> st(s.begin(), s.end());
  if (st.size() < s.size()) {
    cout << "No" << endl;
    return 0;
  }
  bool lower = false, upper = false;
  for (auto c : s) {
    if ('a' <= c && c <= 'z')
      lower = true;
    if ('A' <= c && c <= 'Z')
      upper = true;
  }
  if (lower && upper)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
#endif
