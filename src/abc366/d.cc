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
  vector<vector<vector<ll>>> am(n, vector<vector<ll>>(n, vector<ll>(n)));
  
  vector<vector<vector<ll>>> sm(n, vector<vector<ll>>(n, vector<ll>(n, 0)));
  rep(i, n) {
    rep(r, n) {
      rep(c, n) {
		cin >> am[i][r][c];
        sm[i][r][c] = am[i][r][c];
        if (r)
          sm[i][r][c] += sm[i][r - 1][c];
        if (c)
          sm[i][r][c] += sm[i][r][c - 1];
        if (r && c)
          sm[i][r][c] -= sm[i][r - 1][c - 1];
      }
    }
  }
  // rep(i, n) {
  //   rep(r, n) {
  //     rep(c, n) {
  // 		cout << sm[i][r][c] << " ";
  //     }
  // 	  cout << endl;
  //   }
  // }

  int q;
  cin >> q;

  rep(_, q) {
    int xl, xr, yl, yr, zl, zr;
    cin >> xl >> xr >> yl >> yr >> zl >> zr;
    xl--;
    xr--;
    yl--;
    yr--;
    zl--;
    zr--;
    ll res = 0;
    for (int i = xl; i <= xr; i++) {
      res += sm[i][yr][zr];
	  //dbg(res);
      if (yl) {
        res -= sm[i][yl - 1][zr];
		//dbg("dec", sm[i][yl - 1][zr]);
      }
      if (zl) {
        res -= sm[i][yr][zl - 1];
		//dbg("dec", sm[i][yr][zl - 1]);
      }
      if (yl && zl) {
        res += sm[i][yl - 1][zl - 1];
		//dbg("inc", sm[i][yl - 1][zl - 1]);
      }
	  //dbg("result, res", res);
    }
    cout << res << endl;
  }

  return 0;
}
