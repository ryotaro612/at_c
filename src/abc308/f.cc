#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef ONLINE_JUDGE
int main() {
  ll n, m, res = 0;
  cin >> n >> m;
  vector<ll> pv(n), lv(m), dv(m);
  set<pair<ll, int>> st;
  rep(i, n) {
    cin >> pv[i];
    res += pv[i];
    st.insert({pv[i], i});
  };
  debug("all", res);
  sort(begin(pv), end(pv));
  vector<pair<ll, ll>> dl(m);
  rep(i, m) cin >> lv[i];
  rep(i, m) cin >> dv[i];
  rep(i, m) { dl[i] = {dv[i], lv[i]}; }
  sort(begin(dl), end(dl), greater<pair<ll, ll>>());
  debug("pv", pv);
  debug(dl);
  rep(i, m) {
    auto [d, l] = dl[i];
    auto iter = st.lower_bound({l, 0});
    if(iter!=st.end()) {
      st.erase(iter);
      res -= d;
    }
  }
  cout << res << endl;
  return 0;
}
#endif
