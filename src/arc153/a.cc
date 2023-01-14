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
  cin >> n;
  string s = to_string(--n);
  string res(9, '0');
  vector<int> pos = {7, 6, 4, 3, 2, 0};
  rep(i, s.size()) { res[pos[i]] = s[s.size() - 1 - i]; }
  res[0] += 1;
  res[1] = res[0];
  res[5] = res[4];
  res[8] = res[6];
  cout << res << endl;
  return 0;
}
#endif
