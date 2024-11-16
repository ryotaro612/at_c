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
  int n;
  cin >> n;
  vector<int> av(n), bv(n);
  int bound = 0;
  rep(i, n) {
    cin >> av[i] >> bv[i];
    av[i]--;
    bound += bv[i];
  }
  if (bound % 3) {
    cout << -1 << endl;
    return 0;
  }
  bound /= 3;

  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(bound + 1, vector<int>(bound + 1, 1000000)));
  dp[0][0][0] = 0;
  rep(i, n) {
    if (av[i] == 0) {
      rep(a, bound + 1) {
        rep(b, bound + 1) {
          if (a + bv[i] <= bound)
            dp[i + 1][a + bv[i]][b] = min(dp[i][a][b], dp[i + 1][a + bv[i]][b]);

          if (b + bv[i] <= bound)
            dp[i + 1][a][b + bv[i]] =
                min(dp[i][a][b] + 1, dp[i + 1][a][b + bv[i]]);

          dp[i + 1][a][b] = min(dp[i + 1][a][b], dp[i][a][b] + 1);
        }
      }
    } else if (av[i] == 1) {
      rep(a, bound + 1) {
        rep(b, bound + 1) {

          if (a + bv[i] <= bound)
            dp[i + 1][a + bv[i]][b] =
                min(dp[i][a][b] + 1, dp[i + 1][a + bv[i]][b]);

          if (b + bv[i] <= bound)
            dp[i + 1][a][b + bv[i]] = min(dp[i][a][b], dp[i + 1][a][b + bv[i]]);

          dp[i + 1][a][b] = min(dp[i + 1][a][b], dp[i][a][b] + 1);
        }
      }
    } else {
      rep(a, bound + 1) {
        rep(b, bound + 1) {

          if (a + bv[i] <= bound)
            dp[i + 1][a + bv[i]][b] =
                min(dp[i][a][b] + 1, dp[i + 1][a + bv[i]][b]);

          if (b + bv[i] <= bound)
            dp[i + 1][a][b + bv[i]] =
                min(dp[i][a][b] + 1, dp[i + 1][a][b + bv[i]]);

          dp[i + 1][a][b] = min(dp[i + 1][a][b], dp[i][a][b]);
        }
      }
    }
  }

  if (dp[n][bound][bound] < 1000000)
    cout << dp[n][bound][bound] << endl;
  else
    cout << -1 << endl;
  return 0;
}
