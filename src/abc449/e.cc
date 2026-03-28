#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
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

template <typename E> class Bit {
public:
  Bit(int n) : bit(vector<E>(n + 1, 0)) {}

  E get(int i) { return sum(i + 1) - sum(i); }

  /**
   *  sum of arr[0,to)
   */
  E sum(int to) {
    E res = 0;
    while (to) {
      res += bit[to];
      to -= to & -to;
    }
    return res;
  }
  /**
   * sum of arr[from,to)
   */
  E sum_range(int from, int to) { return sum(to) - sum(from); }

  void update(int pos, E v) {
    add(pos, -get(pos));
    add(pos, v);
  }

  void add(int pos, E v) {
    pos++;
    while (pos < static_cast<int>(bit.size())) {
      bit[pos] += v;
      pos += pos & -pos;
    }
  }
  ll get_kth(int i) {
    // rep(a, bit.size() - 1) { dbg(a, sum(a)); }
    ll lb = -1, ub = bit.size() - 1;
    while (ub - lb > 1) {
      ll mid = (lb + ub) / 2ll;
      if (i <= sum(mid + 1)) { // sum(mid+1) < i;
        ub = mid;
      } else {
        lb = mid;
      }
    }
    dbg(i, ub);
    return ub;
  }

private:
  vector<E> bit;
};

int main() {
  ll n, m, q;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i], av[i]--;
  cin >> q;
  vector<ll> res(q);
  vector<pair<ll, int>> qs;
  rep(i, q) {
    ll x;
    cin >> x;
    x--;
    if (x < n) {
      res[i] = av[x];
      continue;
    }
    qs.emplace_back(x, i);
  }
  sort(qs.rbegin(), qs.rend());
  vector<vector<int>> adds(n + 1);
  {
    vector<ll> freq(m);
    rep(i, n) freq[av[i]]++;
    rep(i, m) adds[freq[i]].emplace_back(i);
  }
  Bit<ll> bit(m);
  ll num = 0;
  ll l = n;
  rep(c, n + 1) {
    for (int i : adds[c]) {
      bit.add(i, 1);
      num++;
    }
    while (qs.size() && qs.back().first < l + num) {
      auto [x, i] = qs.back();
      qs.pop_back();
      res[i] = bit.get_kth(x - l + 1ll);
    }
    l += num;
  }
  while (qs.size()) {
    auto [x, qi] = qs.back();
    qs.pop_back();
    res[qi] = (x - l) % m;
  }

  rep(i, q) cout << res[i] + 1 << endl;

  return 0;
}
