#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}

int solve(string s, int k) {
  int res = 0;
  int n = s.size();
  rep(i, n - (k - 1)) {
    bool ok = true;
    for (int j = 0; j < k; j++) {
      if (s[i + j] != 'O') {
        ok = false;
      }
    }
    if (ok) {
      res++;
      for (int j = 0; j < k; j++) {
		s[i+j] = 'X';
      }
    }
  }
  return res;
}
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int res = solve(s, k);
  reverse(begin(s), end(s));
  res = max(res, solve(s, k));
  cout << res << endl;
  return 0;
}
