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
  int n, d;
  cin >> n >> d;
  if ((n - 1) / 2 < d) {
    cout << "No\n";
    return 0;
  }
  set<pair<int, int>> edges;
  for (int step = 1; step < n; step++) {
    bool add = false;
    rep(i, n) {
      if (int(edges.size()) < n * d) {
        int other = (i + step) % n;
        if (edges.count({min(i, other), max(i, other)}) == 0) {
          edges.insert({min(i, other), max(i, other)});
          add = true;
        }
      }
    }
    if (int(edges.size()) == n * d || !add)
      break;
  }
  if (int(edges.size()) != n * d) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (auto [u, v] : edges) {
    cout << u + 1 << " " << v + 1 << "\n";
  }

  return 0;
}
#endif
