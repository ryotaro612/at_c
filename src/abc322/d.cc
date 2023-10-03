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

vector<pair<int, int>> extract(vector<string> grid) {
  vector<pair<int, int>> res;
  rep(i, 4) {
    rep(j, 4) {
      if (grid[i][j] == '#')
        res.push_back({i, j});
    }
  }
  return res;
}
vector<pair<int, int>> rotate(vector<pair<int, int>> &grid) {
  vector<pair<int, int>> res(grid.size());
  rep(i, grid.size()) { res[i] = {grid[i].second, 3 - grid[i].first}; }
  return res;
}

bool is_filled(vector<pair<int, int>> &a, vector<pair<int, int>> &b,
               vector<pair<int, int>> &c) {

  vector<vector<pair<int, int>>> stk = {a, b, c};
  vector<vector<bool>> grid(4, vector<bool>(4, false));

  rep(row, 4) {
    rep(col, 4) {
      if (grid[row][col])
        continue;
      if (stk.empty())
        return false;
      vector<pair<int, int>> cells = stk.back();
      sort(begin(cells), end(cells));
      int dr = row - cells[0].first, dc = col - cells[0].second;
      for (auto [i, j] : cells) {
        int rr = i + dr, cc = j + dc;
        if (0 <= rr && rr <= 3 && 0 <= cc && cc <= 3 && !grid[rr][cc]) {
          grid[rr][cc] = true;
        } else
          return false;
      }
      stk.pop_back();
    }
  }
  return true;
}

int main() {
  vector<string> grid(12);
  for (int i = 0; i < 12; i++) {
    cin >> grid[i];
  }

  vector<vector<pair<int, int>>> cells(3);
  vector<pair<int, int>> poly[3][4];
  rep(i, 3) {
    cells[i] =
        extract(vector<string>(begin(grid) + i * 4, begin(grid) + (i + 1) * 4));
    poly[i][0] = cells[i];
    rep(j, 3) {
      cells[i] = rotate(cells[i]);
      poly[i][j + 1] = cells[i];
    }
  }

  rep(i, 4) {
    rep(j, 4) {
      rep(k, 4) {
        if (is_filled(poly[0][i], poly[1][j], poly[2][k]) ||
            is_filled(poly[0][i], poly[2][j], poly[1][k]) ||
            is_filled(poly[1][i], poly[0][j], poly[2][k]) ||
            is_filled(poly[1][i], poly[2][j], poly[0][k]) ||
            is_filled(poly[2][i], poly[1][j], poly[0][k]) ||
            is_filled(poly[2][i], poly[0][j], poly[1][k])) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
