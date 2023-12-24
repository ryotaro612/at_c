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
int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<int> freq(n, 0);
  rep(i, s.size() - 1) {
    if (s[i] == s[i + 1])
      freq[i + 1] = freq[i];
    else
      freq[i + 1] = 1 + freq[i];
  }
  dbg(freq);

  rep(_, q) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    if (l == r) {
      cout << 0 << endl;
      continue;
    }
    int cnt = freq[r] - freq[l];

    dbg(cnt);
    if (s[l] != s[r])
      cnt++;
    if (cnt % 2)
      cout << cnt / 2 + 1 << endl;
    else
      cout << cnt / 2 << endl;
  }

  return 0;
}
