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
  int n, m = 0;
  cin >> n;
  while ((1 << m) < n)
    m++;
  cout << m << endl;
  rep(i, m) {
    vector<int> drink;
    rep(j, n) {
      if (j & (1 << i))
        drink.push_back(j);
    }
    cout << drink.size() << " ";
    rep(j, drink.size()) cout << drink[j]+1 << " \n"[j == (int)drink.size() - 1];
  }
  string s;
  cin >> s;
  int res = 0;
  rep(i, s.size()) {
    if (s[i]-'0') {
      res |= 1 << i;
    }
  }
  cout << res +1<< endl;
  return 0;
}
