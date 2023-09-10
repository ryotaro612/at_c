#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
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

bool cx(int a, int b, int c) {
  if (a < 0 && b > 0 && b == c)
    return false;
  else if (b < 0 && a > 0 && a == c)
    return false;
  else if (c < 0 && a > 0 && a == b)
    return false;
  return true;
}

int main() {
  vector<vector<int>> cm(3, vector<int>(3));
  rep(i, 3) {
    rep(j, 3) { cin >> cm[i][j]; }
  }
  vector<int> order;
  rep(i, 9) order.push_back(i);
  int denom = 0, numerator = 0;
  do {

    vector<vector<int>> am(3, vector<int>(3, -1));
    bool ok = true;
    rep(i, 9) {
      int r = order[i] / 3, c = order[i] % 3;
      am[r][c] = cm[r][c];
      rep(j, 3) {
        ok &= cx(am[r][0], am[r][1], am[r][2]);
        ok &= cx(am[0][c], am[1][c], am[2][c]);
      }
      ok &= cx(am[0][0], am[1][1], am[2][2]);
      ok &= cx(am[0][2], am[1][1], am[2][0]);
      //dbg(i, ok);
    }

    if (ok) {
      numerator++;
      //dbg(order);
      //return 1;
    }

    denom++;
  } while (next_permutation(begin(order), end(order)));
  dbg(denom);
  cout << fixed << setprecision(12) << (ld)numerator / (ld)denom << endl;
  return 0;
}
