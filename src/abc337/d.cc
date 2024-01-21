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
const int inf = 1 << 29;
int solve(string &s, int k) {
  int res = inf;
  deque<char> que;
  int cnt = 0;
  for (auto c : s) {
    if (c == 'x') {
      que = deque<char>();
      cnt = 0;
    } else {
      if (c == '.')
        cnt++;
      if ((int)que.size() == k) {
        char tail = que.front();
        que.pop_front();
        if (tail == '.')
          cnt--;
      }
      que.push_back(c);
      if ((int)que.size() == k) {
        res = min(res, cnt);
      }
    }
  }
  return res;
}
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> grid(h);

  int res = inf;
  rep(i, h) {
    cin >> grid[i];
    res = min(solve(grid[i], k), res);
  }
  rep(i, w) {
    string s;
    rep(r, h) { s.push_back(grid[r][i]); }
    res = min(solve(s, k), res);
  }
  if (res == inf)
    res = -1;
  cout << res << endl;

  return 0;
}
