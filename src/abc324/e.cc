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

int prefix_count(string &s, string &t) {
  int i = 0;
  for (auto c : s) {
    if (t[i] == c) {
      i++;
      if (i == (int)t.size())
        break;
    }
  }
  return i;
}
int main() {
  int n;
  string t, rev_t;
  cin >> n >> t;
  rev_t = string(t);
  reverse(begin(rev_t), end(rev_t));
  vector<string> sv(n);
  vector<int> tail;
  rep(i, n) {
    cin >> sv[i];
    string rev_s = sv[i];
    reverse(begin(rev_s), end(rev_s));
    tail.push_back(prefix_count(rev_s, rev_t));
  }
  sort(begin(tail), end(tail));
  ll res = 0;
  rep(i, n) {
    int cnt = prefix_count(sv[i], t);
    res += tail.end() - lower_bound(begin(tail), end(tail), t.size() - cnt);
  }
  cout << res << endl;
  return 0;
}
