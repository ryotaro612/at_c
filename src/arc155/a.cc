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

bool is_palindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n - 1 - i; i++) {
    if (s[i] != s[n - 1 - i])
      return false;
  }
  return true;
}

pair<string, bool> build(ll k, string &s) {
  ll n = s.size();
  string temp(k, ' ');
  rep(i, min(k, n)) { temp[k - 1 - i] = s[i]; }
  rep(i, min(k, n)) {
    if (temp[i] == ' ')
      temp[i] = s[n - 1 - i];
    else if (temp[i] != s[n - 1 - i])
      return {"", false};
  }
  return {temp, true};
}
bool sub(ll k, string &s) {
  auto [v, res] = build(k, s);
  if (res == false)
    return false;
  return is_palindrome(v + s) && is_palindrome(s + v);
}

bool solve(ll n, ll k, string &s) {
  if (k < 2ll * n) {
    return sub(k, s);
  }
  return sub(k % (2ll * n), s);
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;
    if (solve(n, k, s))
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
  return 0;
}
#endif
