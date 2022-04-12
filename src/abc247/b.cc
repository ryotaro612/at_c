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
  int n;
  cin >> n;
  vector<string> sv(n), tv(n);
  rep(i, n) { cin >> sv[i] >> tv[i]; }

  rep(i, n) {
    unordered_multiset<string> conf;
    rep(j, n) {
      if (i != j) {
        conf.insert(sv[j]);
        conf.insert(tv[j]);
      }
    }
    if (!(conf.find(sv[i]) == conf.end() || conf.find(tv[i]) == conf.end())) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
#endif
