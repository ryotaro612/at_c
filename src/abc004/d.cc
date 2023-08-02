#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif
int steps(int n) { return n * (n + 1) / 2; }

int calc_r(int left, int n) {
  left += 100;
  int right = left + n;
  // [left_r, right_r)
  if (right <= 0)
    return steps(-left) - steps(-right);
  else
    return steps(-left) + steps(right - 1);
}
int calc_b(int right, int n) {
  right -= 100;
  int left = right - n;
  // (left, right]
  if (0 <= left) {
    return steps(right) - steps(left);
  } else { // left < 0
    return steps(right) + steps(-left - 1);
  }
}

int calc_g(int lower, int upper, int n) {
  //[lb, ub]
  if (upper < 0) {
    return steps(n - 1 - upper) - steps(-upper - 1);
  } else if (upper == 0) {
    return steps(n - 1);
  } else if (0 < lower) {
    return steps(lower + n - 1) - steps(lower - 1);
  } else if (0 == lower) {
    return steps(lower + n - 1);
  } else {
    int lb = 0, ub = min(-lower, upper) + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (mid * 2 > n - 1) {
        ub = mid;
      } else
        lb = mid;
    }
    if (lower == -95 && upper == 198) {
      debug("calc_g", ub, lb);
    }
    int count = steps(lb) * 2;
    n -= 2 * lb + 1;
    return count + steps(lb + n) - steps(lb);
  }
}
// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int res = (1ll << 31ll) - 1ll;

  for (int left_r = -800; left_r <= -100; left_r++) {
    for (int right_b = 100; right_b <= 800; right_b++) {
      if (r + g + b > right_b - left_r + 1)
        continue;
      int count = calc_r(left_r, r) + calc_b(right_b, b);
      int left_g = left_r + r, right_g = right_b - b;
      if (left_r == -362 && right_b == 363) {
        debug(calc_r(left_r, r), calc_b(right_b, b));
        debug(left_g, right_g, calc_g(left_g, right_g, g));
      }
      // [left_l, right_g]
      count += calc_g(left_g, right_g, g);
      res = min(res, count);
    }
  }
  cout << res << endl;
  return 0;
}
/**
   example3
    [-362, 363]
   b [199, 363]
   g [-95, 198]
   r [-362, -96]
   -> 88589
 */
