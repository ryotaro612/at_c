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

  ll n, k;
  cin >> n >> k;
  vector<int> xv(n), av(n);
  rep(i, n) {
    cin >> xv[i];
    xv[i]--;
  }
  rep(i, n) { cin >> av[i]; }

  vector<vector<ll>> proceed(n, vector<ll>(60));

  rep(i, n) { proceed[i][0] = xv[i]; }
  rep(j, 59) {
    rep(i, n) { proceed[i][j + 1] = proceed[proceed[i][j]][j]; }
  }
  vector<int> res(n);
  // rep(i, n) {
  // 	dbg(proceed[i]);
  // }
  rep(i, n) {
    ll move = k;
    int pos = i;
    while (move) {
      for (ll j = 60ll; j >=0; j--) {
        if ((1ll << j) <= move) {
          pos = proceed[pos][j];
          move -= (ll)(1ll << (ll)j);
		  break;
        }
      }
	  //dbg(move);
    }
    res[i] = av[pos];
  }

  rep(i, n) { cout << res[i] << " \n"[i == n - 1]; }
  return 0;
}
