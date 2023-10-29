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

bool solve(string &rs, string &cs, vector<vector<string>> &cands,
           vector<string> &grid) {
  if (grid.size() == rs.size())
    return true;
  for (string &cand : cands[rs[grid.size()] - 'A']) {

    grid.push_back(cand);

    bool ok = true;
    rep(c, rs.size()) {
      string alpha;
      rep(r, grid.size()) {
        if (grid[r][c] != '.') {
          alpha.push_back(grid[r][c]);
        }
      }
      if (alpha.size()) {
        ok = ok && alpha[0] == cs[c];
      }
      int freq[3] = {0, 0, 0};
      for (char x : alpha) {
        if (freq[x - 'A'])
          ok = false;
        else
          freq[x - 'A']++;
      }
    }
    if (ok && solve(rs, cs, cands, grid)) {
      return true;
    } else {
      grid.pop_back();
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  string r, c;
  cin >> r >> c;
  vector<vector<string>> cands(3);
  rep(i, 3) {
    string temp = "ABC";
    while ((int)temp.size() < n)
      temp.push_back('.');
    sort(begin(temp), end(temp));
    do {
      for (auto letter : temp) {
        if (letter != '.') {
          cands[letter - 'A'].push_back(temp);
          break;
        }
      }
    } while (next_permutation(begin(temp), end(temp)));
  }
  vector<string> grid;
  if (solve(r, c, cands, grid)) {
    cout << "Yes\n";
    for (auto line : grid)
      cout << line << endl;
  } else
    cout << "No\n";

  return 0;
}
