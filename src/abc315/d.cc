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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> rows(h, vector<int>(26, 0)), cols(w, vector<int>(26, 0));
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      rows[i][s[j] - 'a']++;
      cols[j][s[j] - 'a']++;
    }
  }
  dbg(rows[0][0]);
  vector<bool> used_row(h, false), used_col(w, false);
  int hb = h, wb = w;
  rep(_, h + w) {
    vector<pair<int, int>> row_cands;
    rep(i, h) {
      if (used_row[i])
        continue;

      rep(j, 26) {
        if (rows[i][j] == wb && rows[i][j] >= 2)
          row_cands.push_back({i, j});
      }
    }
    vector<pair<int, int>> col_cands;
    rep(i, w) {
      if (used_col[i])
        continue;
      rep(j, 26) {
        if (cols[i][j] == hb && cols[i][j] >= 2)
          col_cands.push_back({i, j});
      }
    }
    dbg(row_cands);

    for (auto [a, b] : row_cands) {
      used_row[a] = true;
      rep(i, w) { cols[i][b]--; }
      hb--;
    }
    for (auto [a, b] : col_cands) {
      used_col[a] = true;
      rep(i, h) { rows[i][b]--; }
      wb--;
    }
  }
  dbg(hb, wb);
  cout << hb * wb << endl;

  return 0;
}
