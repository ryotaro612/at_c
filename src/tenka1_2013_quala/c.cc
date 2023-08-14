#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #x << " = " << x   \
       << "\e[39m" << endl;
#else
#define dbg(x)
#endif
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type
operator<<(Ostream &os, const Cont &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}
void find_tops2(vector<int> &current, int m, vector<vector<int>> &tops) {
  if ((int)size(current) == m) {
    tops.push_back(vector<int>(current));
    return;
  }
  for (int i = 1; i <= 3; i++) {
    int s = size(current);
    if (s) {
      bool ok = true;
      for (int step = 1; step <= i && s - step >= 0; step++) {
        if (current[s - step] == i)
          ok = false;
      }
      if (ok) {
        current.push_back(i);
        find_tops2(current, m, tops);
        current.pop_back();
      }
    } else {
      current.push_back(i);
      find_tops2(current, m, tops);
      current.pop_back();
    }
  }
}
void find_tops(vector<int> &current, int m, vector<vector<int>> &tops) {
  int s = size(current);
  if (s >= 4 && current[s - 1] == 3 && current[s - 2] == 1 &&
      current[s - 3] == 2 && current[s - 4] == 1 && m - s > 4) {
    m %= 4;
  }
  if (m == 0) {
    tops.push_back(vector<int>(current));
    return;
  }

  for (int i = 1; i <= 3; i++) {

    if (s) {
      bool ok = true;
      for (int step = 1; step <= i && s - step >= 0; step++) {
        if (current[s - step] == i)
          ok = false;
      }
      if (ok) {
        current.push_back(i);
        find_tops(current, m - 1, tops);
        current.pop_back();
      }
    } else {
      current.push_back(i);
      find_tops(current, m - 1, tops);
      current.pop_back();
    }
  }
}
void fill_cols(vector<int> &cur, vector<vector<int>> &prev,
               vector<vector<int>> &rows) {
  int c = size(cur);
  int m = size(prev[0]);
  if (c == m) {
    rows.push_back(vector<int>(cur));
    return;
  }

  for (int step = 1; step <= 3; step++) {
    bool ok = true;
    for (int r = 1; r <= step && (int)size(prev) - r >= 0; r++)
      ok = ok && prev[(int)size(prev) - r][c] != step;
    if (!ok)
      continue;
    for (int a = 1; a <= step && c - a >= 0; a++)
      ok = ok && cur[c - a] != step;
    if (ok) {
      cur.push_back(step);
      fill_cols(cur,prev, rows);
      cur.pop_back();
    }
  }
}
void to_bottom(int n, vector<vector<int>> &prev, int &res) {
  int s = size(prev);
  if (s >= 4 && prev[s - 1][0] == 3 && prev[s - 2][0] == 1 &&
      prev[s - 3][0] == 2 && prev[s - 4][0] == 1 && n - s > 4) {
    n %= 4;
  }  
  if (n==0) {
    for (auto e : prev)
      dbg(e);
    dbg("-------------------------");
    res++;
    return;
  }

  vector<int> temp;
  vector<vector<int>> rows;
  fill_cols(temp, prev, rows);
  for (auto row : rows) {
    prev.push_back(row);
    to_bottom(n-1, prev, res);
    prev.pop_back();
  }
}
int main() {
  int n, m;
  cin >> m >> n;
  vector<vector<int>> tops;
  vector<int> current;
  find_tops(current, m, tops);
  int res = 0;
  for (vector<int> top : tops) {
    vector<vector<int>> rows = {top};
    to_bottom(n-1, rows, res);
  }
  cout << res << endl;

  return 0;
}
