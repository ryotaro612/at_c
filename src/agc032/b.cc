#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  set<pair<int, int>> edges;
  for (int i = 1; i <= n / 2 * 2; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (i + j != 1 + n / 2 * 2) {
        edges.insert({i, j});
      }
    }
  }
  cout << edges.size() << endl;
  for (auto [a, b] : edges) {
    cout << a << " " << b << endl;
  }

  return 0;
}
#endif
