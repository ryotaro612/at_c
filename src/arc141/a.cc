#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <string>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

bool all_same(string &s) {
  set<char> cs(s.begin(), s.end());
  return cs.size() == 1;
}

ll solve(string &s) {
  int n = static_cast<int>(s.size());

  ll res = stoll(string(n - 1, '9'));

  for (int i = 1; i * 2 <= n; i++) {
    if (n % i == 0) {
      string a;
      rep(j, n / i) { a += string(s.begin(), s.begin() + i); }
      if (stoll(a) <= stoll(s))
        res = max(res, stoll(a));
    }
  }
  for (int i = 1; i * 2 <= n; i++) {
    if (n % i != 0)
      continue;
    int repeat = n / i;
    ll num = stoll(string(s.begin(), s.begin() + i)) - 1ll;
    string temp;
    rep(j, repeat) temp += to_string(num);
    res = max(res, stoll(temp));
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    string n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
#endif

/*
ll solve(string &s) {
  if (all_same(s))
    return stoll(s);
  int n = static_cast<int>(s.size());

  set<ll> ignore = {3, 5, 7, 11, 13, 17, 19};
  if (ignore.find(n) != ignore.end()) {
    return stoll(string(n - 1, '9'));
  }

  ll res = 0ll;
  for (int i = 1; i * 2 <= n; i++) {
    if (n % i == 0) {
      string a;
      rep(j, n / i) { a += string(s.begin(), s.begin() + i); }
      if (stoll(a) <= stoll(s))
        res = max(res, stoll(a));
    }
  }
  for (int i = 1; i * 2 <= n; i++) {
    if (n % i != 0)
      continue;
    int repeat = n / i;
    ll num = stoll(string(s.begin(), s.begin() + i)) - 1ll;
    string temp;
    rep(j, repeat) temp += to_string(num);
    res = max(res, stoll(temp));
  }
  return res;
}
*/
