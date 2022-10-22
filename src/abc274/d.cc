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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> av(n);
  rep(i, n) cin >> av[i];

  set<int> xs = {av[0]}, ys = {0};
  for (int i = 1; i < n; i += 2) {
    set<int> temp;
    for (auto e : ys) {
      temp.insert(e + av[i]);
      temp.insert(e - av[i]);
    }
    ys = temp;
  }
  for (int i = 2; i < n; i += 2) {
    set<int> temp;
    for (auto e : xs) {
      temp.insert(e + av[i]);
      temp.insert(e - av[i]);
    }
    xs = temp;
  }

  if (xs.find(x) != xs.end() && ys.find(y) != ys.end())
    cout << "Yes";
  else
    cout << "No";
  cout << endl;

  return 0;
}
#endif
