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
  string s, t;
  cin >> s >> t;
  int n_s = s.size(), n_t = t.size();
  vector<bool> front(n_s + 1, false);
  front[0] = true;
  rep(i, n_s) {
    if (n_t <= i)
      break;
    if (s[i] == t[i] || s[i] == '?' || t[i] == '?')
      front[i + 1] = true;
    else
      break;
  }
  vector<bool> back(n_s + 1, false);
  back[0] = true;
  rep(i, n_s) {
    if (n_t <= i)
      break;
    if (t[n_t - 1 - i] == s[n_s - 1 - i] || t[n_t - 1 - i] == '?' ||
        s[n_s - 1 - i] == '?')
      back[i + 1] = true;
    else
      break;
  }
  rep(i, n_t + 1) {
    if (front[i] && back[n_t - i])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
#endif
