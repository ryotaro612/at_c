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
ll my_pow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}
vector<vector<ld>> mul(vector<vector<ld>> a, vector<vector<ld>> b) {
  vector<vector<ld>> next_mat(2, vector<ld>(2));
  next_mat[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
  next_mat[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
  next_mat[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
  next_mat[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
  return next_mat;
}
int main() {
  ld p;
  ll n;
  cin >> p >> n;
  vector<vector<ld>> mat = {{1.0 - p, p}, {p, 1.0 - p}};
  vector<vector<ld>> base = {{1.0, 0}, {0, 1.0}};
  while (n) {
    if (n & 1)
      base = mul(mat, base);
    n >>= 1;
    mat = mul(mat, mat);
    dbg(mat);
    mat = {{mat[0][0], 1. - mat[0][0]}, {1.0 - mat[0][0], mat[0][0]}};
  }
  dbg(base);
  cout << fixed << setprecision(30) << base[1][0] << endl;
  return 0;
}
