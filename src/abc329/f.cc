#include <bits/stdc++.h>
#include <memory>
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
  cin >> n >> q;
  map<int, unordered_set<int> *> mp;
  rep(i, n) {
    int c;
    cin >> c;
    mp[i] = new unordered_set<int>();
    mp[i]->insert(c);
  }
  rep(_, q) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (mp[a]->size() < mp[b]->size()) {
      for (auto e : *mp[a]) {
        mp[b]->insert(e);
      }
      mp[a]->clear();
    } else {
      for (auto e : *mp[b]) {
        mp[a]->insert(e);
      }
      swap(mp[b], mp[a]);
      mp[a]->clear();
    }
    cout << mp[b]->size() << endl;
  }
  rep(i, n) { delete mp[i]; }
  return 0;
}
