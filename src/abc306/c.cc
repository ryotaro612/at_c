#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void debug_() { cout << endl; }
template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  cout << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) { cout << v[i] << s[i == int(v.size()) - 1]; }
  return os;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n * 3);
  vector<vector<int>> pos(n + 1);
  rep(i, 3 * n) {
    cin >> av[i];
    pos[av[i]].push_back(i);
  }
  vector<pair<int, int>> x;
  for (int i = 1; i <= n; i++) {
    x.push_back({pos[i][1], i});
  }
  sort(x.begin(), x.end());
  rep(i, x.size()) { cout << x[i].second << " \n"[i == int(x.size() - 1)]; }
  return 0;
}
#endif
