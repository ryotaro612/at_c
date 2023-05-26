#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

vector<int> solve(int n, int k, vector<int> av) {
  vector<int> rest;
  int a = 1, b = n * (n + 1) / 2;
  rep(i, n) {
    vector<int> small, large;
    for (int j = i + 1; j < n; j++) {
      if (av[j] < av[i])
        small.push_back(av[j]);
      else if (av[j] > av[i])
        large.push_back(av[j]);
    }

    // cout << "i " << i << " k " << k << " lt " << lt << endl;
    int x = -1;
    if (k < a + int(small.size())) {
      sort(small.begin(), small.end());
      x = small[k - a];
    }
    if (b - int(large.size()) < k) {
      sort(large.begin(), large.end());
      reverse(large.begin(), large.end());
      x = large[b - k];
    }
    if (x != -1) {
      int j = i;
      while (av[j] != x)
        j++;
      reverse(av.begin() + i, av.begin() + j + 1);
      break;
    }
    a += small.size();
    b -= large.size();
  }
  return av;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  vector<int> res = solve(n, k, av);
  rep(i, n) cout << res[i] << " \n"[i == n - 1];
  // for (int i = 1; i <= n * (n + 1) / 2; i++) {
  //   cout << " --- " << endl;
  //   res = solve(n, i, av);
  //   rep(j, n) cout << res[j] << " \n"[j == n - 1];
  // }
  return 0;
}
#endif
