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
  int n, m;
  cin >> n >> m;
  vector<int> av(m), bv(n);
  rep(i, n) { bv[i] = i; }
  rep(i, m) {
    cin >> av[i];
    av[i]--;
    swap(bv[av[i]], bv[av[i] + 1]);
  }
  vector<int> v_to_i(n);
  rep(i, n) { v_to_i[bv[i]] = i; }
  // rep(i, n) cout << v_to_i[i] << endl;
  //  cout << "aa" << endl;
  vector<int> cv(n);
  rep(i, n) cv[i] = i;

  rep(i, m) {
    if (cv[av[i]] == 0) {
      cout << v_to_i[cv[av[i] + 1]] + 1 << endl;
    } else if (cv[av[i] + 1] == 0) {
      cout << v_to_i[cv[av[i]]] + 1 << endl;
    } else {
      cout << v_to_i[0] + 1 << endl;
    }
    swap(cv[av[i]], cv[av[i] + 1]);
  }

  return 0;
}
#endif
