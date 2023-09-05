#include <algorithm>
#include <bits/stdc++.h>
#include <set>
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
int sub(vector<int> &av) {
  dbg(av);
  map<int, vector<int>> mp;
  int n = av.size();
  rep(i, n) { mp[av[i]].push_back(i); }
  int res = 0, cur = -1;

  for (auto &[_, vec] : mp) {
    auto iter = lower_bound(begin(vec), end(vec), cur);
    dbg(vec);
    if (iter == begin(vec))
      cur = *rbegin(vec);
    else {
      res++;
      cur = *prev(iter);
    }
    dbg(cur, res);
  }
  dbg("--");
  return res + 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  vector<int> bv;
  for (int i = 1; i < n; i++)
    bv.push_back(av[i]);
  bv.push_back(av[0]);

  cout << min(sub(av), sub(bv)) << endl;
  return 0;
}
