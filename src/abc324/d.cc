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
  int n;
  string s;
  cin >> n >> s;
  vector<int> counter(10, 0);
  rep(i, n) { counter[s[i] - '0']++; }


  ll res = 0;
  for (ll i = 0; i < 3162278ll; i++) {
    string t = to_string(i * i);
    vector<int> cnt(10, 0);

    rep(j, t.size()) { cnt[t[j] - '0']++; }
    bool ok = true;
    for (int j = 1; j < 10; j++) {
      if (cnt[j] != counter[j])
        ok = false;
    }
    if (ok && (cnt[0] <= counter[0]))
      res++;
  }
  cout << res << endl;
  return 0;
}
