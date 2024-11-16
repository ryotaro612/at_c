
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

ll calc(ll target, ll a, ll p, ll b, ll q, ll threshold) {
  ll common = a * b;
  ll n_chunk = target / common;
  ll chunk_cost = min(common / a * p, common / b * q);
  if(n_chunk)
	n_chunk-=1ll;
  ll res = chunk_cost * n_chunk;

  // のこりの作る製品数
  target -= n_chunk * common;
  if (target <= 0)
    return res;

  ll max_s_count = target / a + 1ll;

  ll cand = 1000000000000000ll;
  for (ll n_s = 0; n_s <= max_s_count; n_s++) {
    ll rest = target - n_s * a;
    if (rest <= 0) {
      cand = min(cand, n_s * p);
      continue;
    }
    if (rest % b) {
      cand = min(cand, n_s * p + (rest / b + 1ll) * q);
    } else {
      cand = min(cand, n_s * p + (rest / b) * q);
    }
  }
  ll max_t_count = target / b + 1ll;
  for (ll n_t = 0; n_t <= max_t_count; n_t++) {
    ll rest = target - n_t * b;
    if (rest <= 0) {
      cand = min(cand, n_t * q);
      continue;
    }
    if (rest % a) {
      cand = min(cand, (rest / a + 1ll) * p + n_t * q);
    } else {
      cand = min(cand, (rest / a) * p + n_t * q);
    }
  }
  return res + cand;
}
int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> av(n), pv(n), bv(n), qv(n);
  rep(i, n) { cin >> av[i] >> pv[i] >> bv[i] >> qv[i]; }
  ll ub = numeric_limits<ll>::max() - 2ll;
  ll lb = -1;
  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    bool ok = true;

    ll total_cost = 0;
    rep(i, n) {
      ll cost = calc(mid, av[i], pv[i], bv[i], qv[i], x - total_cost);
      if (cost < 0 || total_cost + cost > x) {
        ok = false;
        break;
      }
      total_cost += cost;
    }

    if (ok)
      lb = mid;
    else
      ub = mid;
  }
  cout << lb << endl;

  return 0;
}
