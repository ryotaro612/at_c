#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

bool backtrack(int i, int n_us, string acc, vector<string> &sv,
               set<string> &ts) {
  if (i == (int)sv.size()) {
    if (n_us == 0) {
      if (ts.find(acc) == ts.end() && acc.size() >= 3 && acc.size() <= 16) {
        cout << acc << endl;
        return true;
      } else
        return false;
    } else {
      return false;
    }
  }
  if (n_us == 0) {
    if (i == (int)sv.size() - 1) {
      return backtrack(i + 1, n_us, acc + sv[i], sv, ts);
    } else
      return false;
  }
  if (acc.size() > 0 && backtrack(i, n_us - 1, acc + "_", sv, ts)) {
    return true;
  }
  if (i == 0 || acc.back() == '_') {
    return backtrack(i + 1, n_us, acc + sv[i], sv, ts);
  }
  return false;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  vector<string> tv(m);
  rep(i, m) cin >> tv[i];

  sort(sv.begin(), sv.end());
  set<string> ts(tv.begin(), tv.end());

  int length = 0;
  for (auto s : sv)
    length += s.size();
  do {
    for (int i = 0; length + i + n - 1 <= 16; i++) {
      if (backtrack(0, n - 1 + i, "", sv, ts)) {
        return 0;
      }
    }
  } while (next_permutation(sv.begin(), sv.end()));
  cout << -1 << endl;
  return 0;
}
#endif
