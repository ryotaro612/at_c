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
  map<string, int> mp;
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) { cin >> sv[i]; }
  rep(i, n) {
    string s = sv[i];
    mp[s] += 1;
    if (mp[s] == 1) {
      cout << s << endl;
    } else {
      cout << s << "(" << mp[s] - 1 << ")" << endl;
    }
  }
  return 0;
}
#endif
