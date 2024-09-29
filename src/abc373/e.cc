#include <algorithm>
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
  ll n, m, k;
  cin >> n >> m >> k;
  vector<pair<ll, ll>> av(n);
  rep(i, n) {
    ll a;
    cin >> a;
    av[i] = {a, i};
  }
  sort(begin(av), end(av));
  vector<ll> prefix(n + 1, 0);
  rep(i, n) { prefix[i + 1] = prefix[i] + av[i].first; }
  ll rest = k - prefix[n];
  // dbg(rest);
  vector<ll> res(n);
  dbg(av);
  rep(i, n) {
    ll ub = rest + 1ll;
    ll lb = -1ll;
    dbg(i);
    while (ub - lb > 1ll) {
      ll mid = (ub + lb) / 2ll;
	  // 投票数
      ll cand = av[i].first + mid;

      auto iter = upper_bound(begin(av), end(av), (pair<ll, ll>){cand, n});
      ll num_larger = end(av) - iter;
      if (num_larger >= m) {
		lb = mid;
		continue;
      }
      ll n_competitor = m - num_larger;
	  // 
      ll right = n - num_larger - 1ll;
      ll left = right - n_competitor + 1ll;

	 if(left == 0) {
		ub = mid;
		continue;
	  }
      if (left <= i && i <= right)
        left--;

      ll x = prefix[right + 1] - prefix[left];
      dbg(left, right, n_competitor, num_larger, cand);
      if (left <= i && i <= right)
        x -= av[i].first;
	  dbg((cand + 1ll) * n_competitor - x,  rest - mid)
      if ((cand + 1ll) * n_competitor - x <= rest - mid) {
        lb = mid;
      } else
        ub = mid;
    }
    if (ub >= rest + 1ll)
      res[av[i].second] = -1;
    else
      res[av[i].second] = ub;
  }

  rep(i, n) { cout << res[i] << " \n"[i == n - 1]; }
  return 0;
}
