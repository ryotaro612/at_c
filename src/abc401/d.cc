#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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

vector<vector<ll>> new_dp(string s) {
  int n = s.size();
  vector<vector<ll>> dp(n, vector<ll>(2, -100000000ll));
  // dp[i][0] i番目がoのときのoの最大値
  // dp[i][1] i番目が.のときのoの最大値
  rep(i, n) {
    if (i == 0) {
      if (s[i] == 'o') {
        dp[i][0] = 1ll;
      } else if (s[i] == '.') {
        dp[i][1] = 0;
      } else {
        if (n == 1 || (i < n - 1 && s[i + 1] != 'o')) {
          dp[i][0] = 1ll;
        }
        dp[i][1] = 0ll;
      }
      continue;
    }
    if (s[i] == 'o') {
      dp[i][0] = dp[i - 1][1] + 1ll;
    } else if (s[i] == '.') {
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    } else {
      if (i == n - 1 || (i < n - 1 && s[i + 1] != 'o')) {
        dp[i][0] = dp[i - 1][1] + 1ll;
      }
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  return dp;
}

vector<vector<ll>> new_dp_rev(string s) {
  reverse(s.begin(), s.end());
  vector<vector<ll>> dp = new_dp(s);
  reverse(dp.begin(), dp.end());
  return dp;
}

vector<ll> calc_mini(string s) {
  vector<ll> res(s.size(), 0);
  rep(i, s.size()) {
    if (s[i] == 'o') {
      res[i] = 1;
    }
    if (i) {
      res[i] += res[i - 1];
    }
  }
  return res;
}

vector<ll> calc_mini_rev(string s) {
  reverse(s.begin(), s.end());
  vector<ll> res = calc_mini(s);
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (n == 1) {
    if (k == 1) {
      s[0] = 'o';
    } else {
      s[0] = '.';
    }
    cout << s << endl;
    return 0;
  }

  for (int i = 1; i < n - 1; i++) {
    if (s[i - 1] == 'o' || s[i + 1] == 'o') {
      s[i] = '.';
    }
  }

  auto mini_dp = calc_mini(s);
  auto mini_dp_rev = calc_mini_rev(s);

  rep(i, n) {
    if (s[i] != '?')
      continue;
    if (i == 0) {
      if (k <= mini_dp_rev[i + 1]) {
        s[i] = '.';
      }
    } else if (i == n - 1) {
      if (k <= mini_dp[n - 2]) {
        s[i] = '.';
      }
    } else {
      if (k <= mini_dp[i - 1] + mini_dp_rev[i + 1]) {
        s[i] = '.';
      }
    }
  }

  auto dp = new_dp(s);
  auto dp_rev = new_dp_rev(s);

  string res(n, '?');
  dbg(dp);
  dbg(dp_rev);
  rep(i, n) {
    if (s[i] == 'o') {
      res[i] = 'o';
      continue;
    }
    if (s[i] == '.') {
      res[i] = '.';
      continue;
    }

    if (i == 0) {
      if (max(dp_rev[i + 1][0], dp_rev[i + 1][1]) < k) {
        res[i] = 'o';
      }
      continue;
    }

    if (i == n - 1) {
      if (max(dp[i - 1][0], dp[i - 1][1]) < k) {
        res[i] = 'o';
      }
      continue;
    }

    bool o_ok = false, x_ok = false;
    if (k <= max(dp[i - 1][0], dp[i - 1][1]) +
                 max(dp_rev[i + 1][0], dp_rev[i + 1][1])) {
      x_ok = true;
    }
    if (1 + dp[i - 1][1] + dp_rev[i + 1][1] >= k) {
      o_ok = true;
    }
    dbg(x_ok, o_ok);
    if (o_ok && !x_ok) {
      res[i] = 'o';
    } else if (!o_ok && x_ok) {
      res[i] = '.';
    }
  }
  cout << res << endl;

  return 0;
}
