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
  vector<string> sv(10);
  rep(i, 10) cin >> sv[i];
  vector<int> temp;
  rep(i, 10) {
    if (sv[i] != "..........")
      temp.push_back(i);
  }
  cout << temp[0] + 1 << " " << temp.back() + 1 << endl;
  string s = sv[temp[0]];
  temp = vector<int>();
  rep(i, s.size()) {
    if (s[i] == '#')
      temp.push_back(i);
  }
  cout << temp[0] + 1 << " " << temp.back() + 1 << endl;

  return 0;
}
#endif
