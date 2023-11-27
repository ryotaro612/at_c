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

ll calc_cost(ll width, vector<pair<ll, ll>> &v) {
  deque<pair<ll, ll>> que(begin(v), end(v));
  ll cost = 0;
  while (width < que.back().first - que.front().first) {
    if (que.front().second <= que.back().second) {
      auto [pos, freq] = que.front();
      que.pop_front();
      if (width <= que.back().first - que.front().first) {
        cost += freq * (que.front().first - pos);
        auto [pos2, freq2] = que.front();
        que.pop_front();
        que.push_front({pos2, freq2 + freq});
      } else {
        return cost + freq * ((que.back().first - width) - pos);
      }
    } else {
      auto [pos, freq] = que.back();
      que.pop_back();
      if (width <= que.back().first - que.front().first) {
        cost += freq * (pos - que.back().first);
	auto [pos2, freq2] = que.back();
	que.pop_back();
	que.push_back({pos2, freq + freq2});
      } else {
        return cost + freq * (pos - (width + que.front().first));
      }
    }
  }
  return cost;
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  map<ll, int> freq_x, freq_y;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    freq_x[x]++;
    freq_y[y]++;
  }
  vector<pair<ll, ll>> xv, yv;
  for (auto [pos, freq] : freq_x) {
    xv.push_back({pos, freq});
  }
  for (auto [pos, freq] : freq_y) {
    yv.push_back({pos, freq});
  }

  ll ub = 100000000000000ll, lb = -1;
  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    ll cost_x = calc_cost(mid, xv);
    ll cost_y = calc_cost(mid, yv);
    if (cost_x + cost_y <= k)
      ub = mid;
    else
      lb = mid;
  }
  cout << ub << endl;
  return 0;
}
