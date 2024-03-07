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

int calc_area2(int x1, int y1, int z1, int x2, int y2, int z2) {
  int x = max(min(x1, x2) + 7 - max(x1, x2), 0);
  int y = max(min(y1, y2) + 7 - max(y1, y2), 0);
  int z = max(min(z1, z2) + 7 - max(z1, z2), 0);
  return x * y * z;
}

int calc_area3(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3,
               int z3) {
  int x = max(min(min(x1, x2), x3) + 7 - max(max(x1, x2), x3), 0);
  int y = max(min(min(y1, y2), y3) + 7 - max(max(y1, y2), y3), 0);
  int z = max(min(min(z1, z2), z3) + 7 - max(max(z1, z2), z3), 0);
  return x * y * z;
}

int main() {
  int v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  rep(x1, 15) {
    rep(y1, 15) {
      rep(z1, 15) {
        rep(x2, 15) {
          rep(y2, 15) {
            rep(z2, 15) {
              ;
              int a = calc_area3(7, 7, 7, x1, y1, z1, x2, y2, z2);
              int b1 = calc_area2(7, 7, 7, x1, y1, z1);
              int b2 = calc_area2(7, 7, 7, x2, y2, z2);
              int b3 = calc_area2(x1, y1, z1, x2, y2, z2);
              int b = b1 + b2 + b3 - 3 * a;
              int c = 3 * 7 * 7 * 7 - 2 * b - 3 * a;
              if (v1 == c && b == v2 && v3 == a) {
                cout << "Yes\n";
                cout << "7 7 7 ";
                cout << x1 << " " << y1 << " " << z1 << " ";
                cout << x2 << " " << y2 << " " << z2 << "\n";
                return 0;
              }
            }
          }
        }
      }
    }
  }

  cout << "No\n";

  return 0;
}
