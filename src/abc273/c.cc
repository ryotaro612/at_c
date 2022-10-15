#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }

  set<ll> s(av.begin(), av.end());
  vector<ll> sv(s.begin(), s.end());

  vector<int> res(n, 0);

  for (auto a : av) {
    int num = distance(upper_bound(sv.begin(), sv.end(), a), sv.end());
    res[num]++;
  }

  for (auto &e : res)
    cout << e << endl;

  return 0;
}
#endif
