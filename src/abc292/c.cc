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

ll sub(int n) {
  ll res = 0ll;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i == n / i)
        res++;
      else
        res += 2;
    }
  }

  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  ll res = 0ll;
  for (int i = 1; i <= n - 1; i++) {
    res += sub(i) * sub(n - i);
  }
  cout << res << endl;
  return 0;
}
#endif
