#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;

  vector<string> sv(h), tv(h);
  rep(i, h) cin >> sv[i];
  rep(i, h) cin >> tv[i];

  map<string, int> count_s, count_t;
  rep(i, w) {
    string temp_s;
    string temp_t;
    rep(j, h) {
      temp_s.push_back(sv[j][i]);
      temp_t.push_back(tv[j][i]);
    }
    count_s[temp_s]++;
    count_t[temp_t]++;
  }

  if (count_s == count_t) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;

  return 0;
}
//#endif
