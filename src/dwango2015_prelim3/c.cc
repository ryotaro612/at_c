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
int main() {
  int n;
  cin >> n;
  vector<ld> ev(n + 1, 0);
  vector<vector<ld>> pv(n + 1, vector<ld>(n + 1, 0));
  vector<vector<vector<ld>>> patterns(
      n + 1, vector<vector<ld>>(n + 1, vector<ld>(n + 1, 0)));

  patterns[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    rep(r, i + 1) {
      rep(s, i - r + 1) {
        int p = i - r - s;
        if (p) {
          patterns[i][r][s] =
              (ld)i / (ld)((i - r - s) * 3) * patterns[i - 1][r][s];
        } else if (s) {
          patterns[i][r][s] = (ld)i / (ld)(s * 3) * patterns[i - 1][r][s - 1];
        } else {
          patterns[i][r][s] = (ld)i / (ld)(r * 3) * patterns[i - 1][r - 1][s];
        }

        if ((r == 0 && s == 0 && p) || (r == 0 && s && p == 0) ||
            (r && s == 0 && p == 0) || (r == s && s == p))
          pv[i][i] += patterns[i][r][s];
        else if (r == 0) {
          if (s < p)
            pv[i][s] += patterns[i][r][s];
          else if (p < s)
            pv[i][p] += patterns[i][r][s];
          else
            pv[i][s] += patterns[i][r][s];
        } else if (s == 0) {
          if (r < p)
            pv[i][r] += patterns[i][r][s];
          else if (p < r)
            pv[i][p] += patterns[i][r][s];
          else
            pv[i][p] += patterns[i][r][s];
        } else if (p == 0) {
          if (r < s)
            pv[i][r] += patterns[i][r][s];
          else if (s < r)
            pv[i][s] += patterns[i][r][s];
          else
            pv[i][r] += patterns[i][r][s];
        } else if (r < s && r < p)
          pv[i][r] += patterns[i][r][s];
        else if (s < r && s < p)
          pv[i][s] += patterns[i][r][s];
        else if (p < r && p < s)
          pv[i][p] += patterns[i][r][s];
        else if (s == r) {
          pv[i][r] += patterns[i][r][s];
        } else if (s == p) {
          pv[i][s] += patterns[i][r][s];
        } else if (p == r) {
          pv[i][p] += patterns[i][r][s];
        } else
          assert(false);
      }
    }
  }
  // dbg(patterns);
  rep(i, n + 1) { dbg(i, pv[i]); }
  for (int i = 2; i <= n; i++) {
    ld sum = 0;
    for (int j = 1; j <= i - 1; j++)
      sum += pv[i][j] * ((ld)1 + ev[j]);
    ev[i] = (pv[i][i] + sum) / (1.0 - pv[i][i]);
  }

  cout << fixed << setprecision(12) << ev[n] << endl;
  return 0;
}
