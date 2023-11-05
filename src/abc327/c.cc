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
  vector<vector<int>> grid(9, vector<int>(9));
  rep(i, 9) {
    rep(j, 9) {
      cin >> grid[i][j];
      grid[i][j]--;
    }
  }
  bool ok = true;
  rep(row, 9) {
    set<int> st;
    rep(col, 9) { st.insert(grid[row][col]); }
    ok &= st.size() == 9;
  }
  rep(col, 9) {
    set<int> st;
    rep(row, 9) { st.insert(grid[row][col]); }
    ok &= st.size() == 9;
  }
  vector<pair<int, int>> temp = {{0, 0}, {3, 0}, {6, 0}, {0, 3}, {3, 3},
                                 {6, 3}, {0, 6}, {3, 6}, {6, 6}};
  for (auto [r, c] : temp) {
    set<int> st;
    rep(i, 3) {
      rep(j, 3) { st.insert(grid[r + i][c + j]); }
    }
    ok &= st.size() == 9;
  }
  if (ok) {
    cout << "Yes\n";
  } else
    cout << "No\n";

  return 0;
}
