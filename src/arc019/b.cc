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

int count_palindrome_diff(string &a) {
  int n = a.size();
  int res = 0;
  for (int i = 0; i < n - 1 - i; i++) {
    if (a[i] != a[n - 1 - i])
      res++;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  string a;
  cin >> a;
  int n = a.size();
  int diff = count_palindrome_diff(a);
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  } else if (diff >= 2) {
    cout << 25ll * (ll)a.size() << endl;
    return 0;
  } else if (diff == 0) {
    if (n % 2) {
      cout << 25ll * (ll)(a.size() - 1) << endl;
    } else {
      cout << 25ll * (ll)a.size() << endl;
    }

  } else { // diff == 1
    cout << 25ll * (ll)(a.size() - 2) + 24ll * 2ll << endl;
    return 0;
  }

  return 0;
}
#endif
