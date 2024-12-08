#include <bits/stdc++.h>
#include <queue>
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
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> grid(h);
  rep(i, h) { cin >> grid[i]; }
  vector<pair<int, int>> heats;

  auto que = priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                            greater<tuple<ll, int, int>>>();
  ll inf = 10000000000ll;
  vector<vector<ll>> dists(h, vector<ll>(w, inf));
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == 'H') {
        que.push({0, r, c});
        dists[r][c] = 0;
      }
    }
  }
  while (que.size()) {
    auto [a, r, c] = que.top();
    que.pop();
    if (dists[r][c] < a)
      continue;

    vector<pair<int, int>> neighbors = {
        {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}};
    for (auto [n_r, n_c] : neighbors) {
      if (!(0 <= n_r && n_r < h && 0 <= n_c && n_c < w) ||
          grid[n_r][n_c] == '#') {
        continue;
      }
      if (a + 1 < dists[n_r][n_c]) {
        dists[n_r][n_c] = a + 1;
        que.push({a + 1, n_r, n_c});
      }
    }
  }
  int res  = 0;
  rep(r, h) {
	rep(c, w) {
	  if(grid[r][c] != '#' && dists[r][c] <= d)
		res++;
	}
  }
  rep(i, h) {
	dbg(dists[i]);
  }
  cout << res << endl;

  return 0;
}
