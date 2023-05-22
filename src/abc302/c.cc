#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
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
  int n, m;
  cin >> n >> m;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  sort(sv.begin(), sv.end());
  do {
    bool ok = true;
    rep(i, n - 1) {
      int diff = 0;
      rep(j, m) {
        if (sv[i][j] != sv[i + 1][j])
          diff++;
      }
      if (diff != 1)
        ok = false;
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }

  } while (next_permutation(sv.begin(), sv.end()));
  cout << "No\n";

  return 0;
}
#endif
