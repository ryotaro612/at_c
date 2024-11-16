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
  cin >> n >> q;
  vector<char> hv(q);
  vector<int> tv(q);
  rep(i, q) {
    cin >> hv[i] >> tv[i];
    tv[i]--;
  }
  int left = 0, right = 1;
  int res = 0;
  rep(i, q) {
    dbg(i, left, right);
    if (hv[i] == 'L') {
      int pos = left;
      int cnt = 0;
      int sub = 10000000;
      while (pos != tv[i] && pos != right) {
        cnt++;
        pos++;
        pos %= n;
      }
      if (pos == tv[i]) {
        sub = cnt;
      }
      pos = left;
      cnt = 0;
      while (pos != tv[i] && pos != right) {
        cnt++;
        pos--;
        pos += n;
        pos %= n;
      }
      if (pos == tv[i]) {
        sub = min(sub, cnt);
      }
      dbg('l', sub);
      res += sub;
      left = tv[i];
    } else {
      int pos = right;
      int cnt = 0;
      int sub = 10000000;
      while (pos != tv[i] && pos != left) {
        cnt++;
        pos++;
        pos %= n;
		 dbg(i, tv[i], pos, left);
      }
      if (pos == tv[i]) {
        sub = cnt;
      }
      pos = right;
      cnt = 0;
      while (pos != tv[i] && pos != left) {
        cnt++;
        pos--;
        pos += n;
        pos %= n;
      }
      if (pos == tv[i]) {
        sub = min(sub, cnt);
      }
      res += sub;
      dbg('r', sub);
      right = tv[i];
    }
  }
  cout << res << endl;
  return 0;
}
