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
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> cv(m);
  vector<vector<int>> am(m);
  vector<char> rm(m);
  rep(i, m) {
    cin >> cv[i];
    am[i] = vector<int>(cv[i]);
    rep(j, cv[i]) {
      cin >> am[i][j];
      am[i][j]--;
    }
    cin >> rm[i];
  }
  int res = 0;
  rep(i, 1 << n) {

    bool conflict = false;
    rep(j, m) {
      int count = 0;
      rep(l, cv[j]) {
        if (i & (1 << am[j][l]))
          count++;
      }
      if (!((rm[j] == 'o' && count >= k) || (rm[j] == 'x' && count < k))) {
        conflict = true;
      }
    }
    if (!conflict) {
      res++;
      dbg("ok", i);
    } else {
      dbg("ng", i);
    }
  }
  cout << res << endl;
  return 0;
}
