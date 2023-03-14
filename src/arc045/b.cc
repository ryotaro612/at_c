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
  int n, m;
  cin >> n >> m;
  vector<int> sv(m), tv(m);
  vector<int> rooms(n + 1, 0);
  rep(i, m) {
    cin >> sv[i] >> tv[i];
    rooms[--sv[i]]++;
    rooms[tv[i]]--;
  }
  for (int i = 1; i <= n; i++)
    rooms[i] += rooms[i - 1];
  vector<pair<int, int>> overlap;
  rep(i, n + 1) {
    if (rooms[i] > 1) {
      if (overlap.size() && overlap.back().second == i - 1)
        overlap.back().second = i;
      else
        overlap.push_back({i, i});
    }
  }
  vector<int> res;
  rep(i, m) {
    pair<int, int> left = {sv[i], n + 1};
    auto found = lower_bound(overlap.begin(), overlap.end(), left);
    if (found == overlap.begin())
      continue;
    found = prev(found);
    if (found->first <= sv[i] && tv[i] - 1 <= found->second)
      res.push_back(i + 1);
  }
  cout << res.size() << endl;
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
