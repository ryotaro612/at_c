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
  int n;
  cin >> n;
  vector<int> av(n), res;
  rep(i, n) {
    int a;
    cin >> a;
    if (a % 2 == 0)
      res.push_back(a);
  }
  rep(i, res.size()) { cout << res[i] << " \n"[i == as_int(res.size()) - 1]; }

  return 0;
}
#endif
