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
  vector<int> av(n);
  rep(i, n) { cin >> av[i]; }
  int res = 0;
  rep(i, m) {
    int b;
    cin >> b;
    res += av[--b];
  }
  cout << res << endl;

  return 0;
}
#endif
