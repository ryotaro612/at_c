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
struct Query {
  int i;
  ll l, r;

  int compute_div(ll div_size) const { return l / div_size; }
};

void update(ll &n_patterns, ll v, ll diff, vector<ll> &freq) {
  n_patterns -= freq[v] * (freq[v] - 1ll) * (freq[v] - 2ll) / 6ll;
  freq[v] += diff;
  n_patterns += freq[v] * (freq[v] - 1ll) * (freq[v] - 2ll) / 6ll;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<Query> queries;

  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    queries.push_back({i, --l, --r});
  }
  ll l_div = max(1ll, n / (ll)sqrt(n));
  sort(begin(queries), end(queries),
       [&](const Query &left, const Query &right) {
         if (left.compute_div(l_div) == right.compute_div(l_div)) {
           return left.r < right.r;
         } else
           return left.compute_div(l_div) < right.compute_div(l_div);
       });
  vector<ll> freq(200010, 0);
  for (int i = queries[0].l; i <= queries[0].r; i++) {
    freq[av[i]]++;
  }
  vector<ll> res(q, 0);
  for (auto cnt : freq) {
    res[queries[0].i] += cnt * (cnt - 1ll) * (cnt - 2ll) / 6ll;
  }
  for (int i = 1; i < q; i++) {
    res[queries[i].i] = res[queries[i - 1].i];
    for (int j = queries[i - 1].l; j < queries[i].l; j++) {
      update(res[queries[i].i], av[j], -1, freq);
    }
    for (int j = queries[i - 1].l; j > queries[i].l; j--) {
      update(res[queries[i].i], av[j - 1], 1, freq);
    }

    for (int j = queries[i - 1].r; j < queries[i].r; j++) {
      update(res[queries[i].i], av[j + 1], 1, freq);
    }
    for (int j = queries[i - 1].r; j > queries[i].r; j--) {
      update(res[queries[i].i], av[j], -1, freq);
    }

    // unordered_map<ll, ll> diff;
    // for (int j = queries[i - 1].l; j < queries[i].l; j++) {
    //   diff[av[j]]--;
    // }
    // for (int j = queries[i - 1].l; j > queries[i].l; j--) {
    //   diff[av[j - 1]]++;
    // }

    // for (int j = queries[i - 1].r; j < queries[i].r; j++) {
    //   diff[av[j + 1]]++;
    // }
    // for (int j = queries[i - 1].r; j > queries[i].r; j--) {
    //   diff[av[j]]--;
    // }
    // res[queries[i].i] = res[queries[i - 1].i];
    // for (auto [k, v] : diff) {
    //   res[queries[i].i] -= freq[k] * (freq[k] - 1ll) * (freq[k] - 2ll) / 6ll;
    //   freq[k] += v;
    //   res[queries[i].i] += freq[k] * (freq[k] - 1ll) * (freq[k] - 2ll) / 6ll;
    // }
  }

  for (auto e : res)
    cout << e << endl;
  return 0;
}
