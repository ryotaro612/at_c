#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #x << " = " << x   \
       << "\e[39m" << endl;
#else
#define dbg(x)
#endif
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type
operator<<(Ostream &os, const Cont &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

int decode(string s) {
  return (600 * (s[0] - '0') + 60 * (s[1] - '0') + 10 * (s[3] - '0') +
          (s[4] - '0')) %
         (60 * 24);
}

int const BOUND = 16;
vector<int> ts, te;
int solve(int pattern, vector<int> &dp) {
  if (dp[pattern] < BOUND)
    return dp[pattern];

  int n = ts.size();
  bool ok = true;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      if (((1 << i) & pattern) && ((1 << j) & pattern)) {
        if (ts[i] < ts[j]) {
          ok = ok && (te[i] <= ts[j] && ts[i] < te[i] &&
                      (ts[j] < te[j] || te[j] <= ts[i]));
        } else if (ts[j] < ts[i]) {
          ok = ok && (te[j] <= ts[i] && ts[j] < te[j] &&
                      (ts[i] < te[i] || te[i] <= ts[j]));
        } else
          ok = false;
      }
    }
  }
  if (ok)
    dp[pattern] = 1;
  for (int sub = (pattern - 1) & pattern; sub; sub = (sub - 1) & pattern) {
    dp[pattern] = min(dp[pattern], solve(sub, dp) + solve(sub ^ pattern, dp));
  }
  return dp[pattern];
}

int main() {
  int n;
  cin >> n;
  ts.resize(n), te.resize(n);
  rep(i, n) {
    string s, e;
    cin >> s >> e;
    int a = decode(s), b = decode(e);
    ts[i] = a;
    te[i] = b;
  }
  vector<int> dp(1 << n, BOUND);
  cout << solve((1 << n) - 1, dp) << endl;

  return 0;
}
