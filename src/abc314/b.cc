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

int main() {
  int n;
  cin >> n;
  vector<set<int>> am(n);
  rep(i, n) {
    int c;
    cin >> c;
    vector<int> v(c);
    rep(j, c) cin >> v[j];
    am[i] = set(begin(v), end(v));
  }
  int x;
  cin >> x;
  vector<pair<int, int>> cnt;

  rep(i, n) {
    if (am[i].count(x))
      cnt.push_back({am[i].size(), i + 1});
  }
  dbg(am);
  dbg(cnt);
  sort(begin(cnt), end(cnt));
  vector<int> res;
  rep(i, cnt.size()) {
    if (i && cnt[i - 1].first < cnt[i].first)
      break;
    res.push_back(cnt[i].second);
  }
  cout << res.size() << endl;
  rep(i, res.size()) {
    cout << res[i] << " \n"[i == (int) res.size() - 1];
  }

  return 0;
}
