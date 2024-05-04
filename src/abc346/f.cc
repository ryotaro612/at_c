#include <algorithm>
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

bool is_sub(ll n, string &t, ll k, vector<vector<ll>> &prefix) {
  if (k == 0)
    return true;

  ll n_i = 0;
  ll s_i = 0;

  dbg("----");
  dbg(k);
  rep(i, size(t)) {
    if(n_i >= n)
      return false;
    ll n_k = k;
    vector<ll> &sum = prefix[t[i] - 'a'];
    if (sum.back() == 0)
      return false;
    dbg(i, n_i, s_i);
    while (n_k && n_i <=n) {
      dbg(n_k, n_i, s_i);

      if (s_i) {
        if (sum.back() - sum[s_i] < n_k) {
          n_k -= sum.back() - sum[s_i];
          n_i++;
          s_i = 0;
        } else {
          auto iter = lower_bound(begin(sum), end(sum), sum[s_i] + n_k);
          s_i = iter - begin(sum);
          break;
        }
      } else {
        if (sum.back() < n_k) {
          ll n_loop = n_k / sum.back();
          if (n_loop > 1)
            n_loop--;
          n_k -= n_loop * sum.back();
          n_i += n_loop;
        } else { // n_k <= sum.back()
          auto iter = lower_bound(begin(sum), end(sum), n_k);
          s_i = iter - begin(sum);
          break;
        }
      }
    }
  }
  dbg(n_i, s_i);
  return n_i < n || (n_i == n && s_i == 0);
}

int main() {
  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  ll lb = -1ll, ub = 1000000000000000000ll;

  vector<vector<ll>> prefix(26, vector<ll>(size(s) + 1, 0));
  rep(i, size(s)) {
    rep(j, 26) {
      prefix[j][i + 1] = prefix[j][i];
      if (s[i] - 'a' == j)
        prefix[j][i + 1]++;
    }
  }
  while (ub - lb > 1ll) {
    ll k = (ub + lb) / 2ll;
    if (is_sub(n, t, k, prefix))
      lb = k;
    else
      ub = k;
  }
  cout << lb << endl;
  return 0;
}
