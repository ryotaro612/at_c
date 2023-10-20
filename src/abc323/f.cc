#include <bits/stdc++.h>
#include <limits>
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

// ll solve(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
//   dbg(xa, ya, xb, yb, xc, yc);
//   ll res = numeric_limits<ll>::max();
//   if (xa <= xb && xb <= xc) {
//     if (ya <= yb && yb <= yc) {
//       if (xb == xc) {
//         res = abs(yb - 1ll - ya) + abs(xa - xb) + abs(yc - yb);
//         dbg(res);
//         return res;
//       } else if (yb == yc) {
//         res = abs(xb - 1ll - xa) + abs(ya - yb) + abs(xc - xb);
//         dbg(res);
//         return res;
//       } else {
//         ll cand1 = abs(xb - xa) + abs(yb - 1ll - ya) + abs(yb - yc) +
//                    solve(xb, yc - 1ll, xb, yc, xc, yc);
//         ll cand2 = abs(xb - 1ll - xa) + abs(yb - ya) + abs(xc - xb) +
//                    solve(xc - 1ll, yb, xc, yb, xc, yc);
//         res = min(cand1, cand2);
//         dbg(res);
//         return res;
//       }
//     }
//   }
//   if (xa < xb) {
//     res = solve(-xa, ya, -xb, yb, -xc, yc);
//     dbg(res);
//     return res;
//   }
//   if (ya < yb) {
//     res = solve(xa, -ya, xb, -yb, xc, -yc);
//     dbg(res);
//     return res;
//   }
//   if (xa == xb) {
//     res = 1ll + abs(ya - yb) + solve(xb - 1ll, yb, xb, yb, xc, yc);
//     dbg(res);
//     return res;
//   }
//   if (ya == yb) {
//     res = 1ll + abs(xa - xb) + solve(xb, yb - 1ll, xb, yb, xc, yc);
//     dbg(res);
//     return res;
//   }
//   ll cand1 =
//       abs(xa - (xb - 1ll)) + abs(yb - ya) + solve(xb - 1ll, yb, xb, yb, xc,
//       yc);
//   ll cand2 =
//       abs(xb - xa) + abs(ya - (yb - 1ll)) + solve(xb, yb - 1ll, xb, yb, xc,
//       yc);
//   res = min(cand1, cand2);
//   dbg(res);
//   return res;
// }

ll solve(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
  if (xb == 0 && yb == 0) {
    if (xc == 0 && yc > 0) {
      if (0 < ya && xa == 0) {
        return 1ll + solve(xa + 1ll, ya, xb, yb, xc, yc);
      } else {
        return abs(xa) + abs(-1ll - ya) + yc;
      }
    } else if (xc > 0 && yc == 0)
      return solve(ya, xa, yb, xb, yc, xc);
    else if (xc > 0 && yc > 0) {
      if (xa > 0 && ya == 0) {
        return 1ll + xa + solve(0, -1, xb, yb, xc, yc);
      } else if (xa == 0 && ya > 0) {
        return 1ll + ya + solve(-1, 0, xb, yb, xc, yc);
      } else if (xa == 0 && ya == -1) {
        return 2ll + xc + yc;
      } else if (xa == -1 && ya == 0) {
        return 2ll + xc + yc;
      } else {
        ll cand1 = abs(-1ll - xa) + abs(ya) + solve(-1ll, 0, xb, yb, xc, yc);
        ll cand2 = abs(xa) + abs(-1 - ya) + solve(0, -1ll, xb, yb, xc, yc);
        return min(cand1, cand2);
      }
    } else if (xc < 0) {
      return solve(-xa, ya, -xb, yb, -xc, yc);
    } else if (yc < 0) {
      return solve(xa, -ya, xb, -yb, xc, -yc);
    } else
      assert(false);
  } else {
    return solve(xa - xb, ya - yb, 0, 0, xc - xb, yc - yb);
  }
}

int main() {
  ll xa, xb, ya, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  cout << solve(xa, ya, xb, yb, xc, yc) << endl;
  return 0;
}
