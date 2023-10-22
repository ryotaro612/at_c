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
ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll calc_cost(ll a, ll b) {
  if (a % b == 0)
    return 0;
  return b - a % b;
}

vector<pair<int, ll>> make_order(ll a, vector<ll> &av) {
  int n = av.size();
  vector<pair<int, ll>> res(n);
  rep(i, n) { res[i] = {i, av[i]}; }
  sort(begin(res), end(res), [&](const auto &x, const auto &y) {
    ll cost_x = calc_cost(x.second, a);
    ll cost_y = calc_cost(y.second, a);
    if (cost_x != cost_y)
      return cost_x < cost_y;
    return x.first < y.first;
  });

  return res;
}

ll solve_pair(ll a, ll b, vector<ll> &av) {
  auto xv = make_order(a, av), yv = make_order(b, av);
  if (xv[0].first == yv[0].first) {
    return min(calc_cost(xv[0].second, a) + calc_cost(yv[1].second, b),
               calc_cost(xv[1].second, a) + calc_cost(yv[0].second, b));
  } else
    return calc_cost(xv[0].second, a) + calc_cost(yv[0].second, b);
}

__int128 gcd128(__int128 a, __int128 b) {
  if (b == 0)
    return a;
  return gcd128(b, a % b);
}

__int128 calc_cost128(__int128 a, __int128 b) {
  if (a % b == 0)
    return 0;
  return b - a % b;
}

int main() {
  int n;
  ll a, b, c;
  cin >> n >> a >> b >> c;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll res = numeric_limits<ll>::max();
  ll abc = lcm(a, b);
  abc = lcm(abc, c);
  rep(i, n) {
    if (calc_cost128(av[i], abc) < (__int128)res) {
      res = calc_cost128(av[i], abc);
    }
  }
  dbg(res);
  if (n == 1) {
    cout << res << endl;
    return 0;
  }
  res = min(res, solve_pair(lcm(a, b), c, av));
  dbg(res);
  res = min(res, solve_pair(lcm(a, c), b, av));
  dbg(res);
  res = min(res, solve_pair(lcm(b, c), a, av));
  dbg(res);
  if (n == 2) {
    cout << res << endl;
    return 0;
  }
  auto xv = make_order(a, av), yv = make_order(b, av), zv = make_order(c, av);
  rep(i, 3) {
    rep(j, 3) {
      rep(k, 3) {
        set<int> triple = {xv[i].first, yv[j].first, zv[k].first};
        if ((int)triple.size() == 3) {
          res =
              min(res, calc_cost(xv[i].second, a) + calc_cost(yv[j].second, b) +
                           calc_cost(zv[k].second, c));
        }
      }
    }
  }
  cout << res << endl;

  return 0;
}
