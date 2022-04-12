#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> solve(int n, unordered_map<int, vector<int>> &cache) {
  if (cache.find(n) != cache.end()) {
    return cache[n];
  }
  if (n == 1) {
    return cache[n] = {1};
  }

  vector<int> res(solve(n - 1, cache));
  res.push_back(n);
  vector<int> tail = solve(n - 1, cache);
  for (auto e : tail) {
    res.push_back(e);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  unordered_map<int, vector<int>> cache;
  vector<int> res = solve(n, cache);
  rep(i, res.size()) {
    cout << res[i];
    if (i == (res.size() - 1))
      cout << endl;
    else {
      cout << " ";
    }
  }
  return 0;
}
#endif
