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

void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

bool solve(int n, int m, int k, string s) {
  int count = 0;
  for (int i = 0; i < (int)s.size() - 1;) {
    if (s[i] == s[i + 1]) {
      i++;

    } else {
      count++;
      i += 2;
    }
  }
  return k >= count;
}
int main() {

  int t;
  cin >> t;
  rep(_, t) {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    if (solve(n, m, k, s))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
