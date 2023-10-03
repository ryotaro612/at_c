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
ll pv[6][6][6][6][6];
ll dp[6][6][6][6][6];
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  ll inf = 100000000000000ll;
  rep(a, 6) {
    rep(b, 6) {
      rep(c, 6) {
        rep(d, 6) {
          rep(e, 6) { pv[a][b][c][d][e] = inf; }
        }
      }
    }
  }
  pv[0][0][0][0][0] = 0;
  rep(_, n) {
    ll cost;
    cin >> cost;
    dbg(k);
    vector<int> av(k);
    rep(i, k) cin >> av[i];
    while (av.size() < 5)
      av.push_back(p);

    rep(a, 6) {
      rep(b, 6) {
        rep(c, 6) {
          rep(d, 6) {
            rep(e, 6) { dp[a][b][c][d][e] = pv[a][b][c][d][e]; }
          }
        }
      }
    }
    rep(a, 6) {
      rep(b, 6) {
        rep(c, 6) {
          rep(d, 6) {
            rep(e, 6) {
              int n_a = min(p, a + av[0]);
              int n_b = min(p, b + av[1]);
              int n_c = min(p, c + av[2]);
              int n_d = min(p, d + av[3]);
              int n_e = min(p, e + av[4]);
              dp[n_a][n_b][n_c][n_d][n_e] =
                  min(dp[n_a][n_b][n_c][n_d][n_e], pv[a][b][c][d][e] + cost);
            }
          }
        }
      }
    }
    rep(a, 6) {
      rep(b, 6) {
        rep(c, 6) {
          rep(d, 6) {
            rep(e, 6) { pv[a][b][c][d][e] = dp[a][b][c][d][e]; }
          }
        }
      }
    }
  }
  ll res = pv[p][p][p][p][p];
  if (res == inf)
    cout << -1;
  else
    cout << res;
  cout << endl;

  return 0;
}
