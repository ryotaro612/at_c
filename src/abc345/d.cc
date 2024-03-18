#include <algorithm>
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
bool is_placeable(int h, int w, vector<pair<int, int>> &recs) {
  dbg("is_place", recs);
  vector<vector<bool>> grid(h, vector<bool>(w, false));
  int pos = 0;
  for (auto &[height, width] : recs) {
    while (pos < h * w && grid[pos / w][pos % w]) {
      pos++;
    }
    if (pos == h * w)
      break;

    rep(i, height) {
      rep(j, width) {
        int r = pos / w + i, c = pos % w + j;
        if (0 <= r && r < h && 0 <= c && c < w && !grid[r][c]) {
          grid[r][c] = true;
        } else
          return false;
      }
    }
  }

  rep(r, h) {
    rep(c, w) {
      if (!grid[r][c])
        return false;
    }
  }

  return true;
}
int main() {
  int n, h, w;
  cin >> n >> h >> w;
  vector<int> av(n), bv(n);
  rep(i, n) { cin >> av[i] >> bv[i]; }
  vector<int> perms(n);
  rep(i, n) perms[i] = i;

  do {
    rep(i, 1 << n) {
      vector<pair<int, int>> recs(n);
      rep(j, n) {
        if (i & (1 << j)) {
          recs[j] = {av[perms[j]], bv[perms[j]]};
        } else {
          recs[j] = {bv[perms[j]], av[perms[j]]};
        }
      }
      if (is_placeable(h, w, recs)) {
        cout << "Yes\n";
        return 0;
      }
    }

  } while (next_permutation(begin(perms), end(perms)));
  cout << "No\n";
  return 0;
}
