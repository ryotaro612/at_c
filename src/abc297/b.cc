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

  vector<int> bs, rs;
  int k;
  rep(i, 8) {
    if (s[i] == 'B')
      bs.push_back(i);
    else if (s[i] == 'K')
      k = i;
    else if (s[i] == 'R')
      rs.push_back(i);
  }
  if (bs[0] % 2 == bs[1] % 2) {
    cout << "No" << endl;
    return 0;
  }
  if (rs[0] < k && k < rs[1]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
#endif
