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
bool one_diff(string s, string t) {
  int offset = 0;
  rep(j, s.size()) {
    if (s[j] == t[j+offset])
      continue;
    else if (offset == 0) {
      if (s[j] == t[j+1]) {
        offset++;
        continue;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  return true;
}
int main() {
  int n;
  string t;
  cin >> n >> t;
  vector<int> res;
  rep(i, n) {
    string s;
    cin >> s;
    if (t == s) {
      res.push_back(i);
      continue;
    }
    if (s.size() + 1 == t.size()) {
      if (one_diff(s, t))
        res.push_back(i);
      continue;
    }
    if (s.size() -1 == t.size()) {
      if (one_diff(t, s))
        res.push_back(i);
      continue;
    }
    if (s.size() == t.size()) {
      int diff = 0;
      rep(j, s.size()) { diff += !(s[j] == t[j]); }
      if (diff == 1)
        res.push_back(i);
      continue;
    }
  }
  cout << res.size() << "\n";
  rep(i, res.size()) cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
  return 0;
}
