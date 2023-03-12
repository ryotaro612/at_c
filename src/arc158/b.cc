#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#include <iomanip>
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
  int n;
  cin >> n;
  vector<ld> xv(n);
  rep(i, n) cin >> xv[i];
  vector<ld> pos, neg;
  rep(i, n) {
    if (xv[i] > 0)
      pos.push_back(xv[i]);
    else
      neg.push_back(xv[i]);
  }
  sort(neg.begin(), neg.end(), greater());
  sort(pos.begin(), pos.end(), greater());
  xv = vector<ld>();
  for (auto e : neg)
    xv.push_back(e);
  for (auto e : pos)
    xv.push_back(e);
  if (6 < n) {
    vector<ld> temp;
    rep(i, 3) {
      temp.push_back(xv[i]);
      temp.push_back(xv[xv.size() - 1 - i]);
    }
    xv = temp;
  }
  vector<int> order;
  rep(i, xv.size()) order.push_back(i);
  ld max_res = -1000000000000000, min_res = 1000000000000000;
  do {
    ld temp = (xv[order[0]] + xv[order[1]] + xv[order[2]]) /
              (xv[order[0]] * xv[order[1]] * xv[order[2]]);
    max_res = max(max_res, temp);
    min_res = min(min_res, temp);
  } while (next_permutation(order.begin(), order.end()));
  cout << fixed << setprecision(12) << min_res << endl;
  cout << fixed << setprecision(12) << max_res << endl;
  return 0;
}
#endif
