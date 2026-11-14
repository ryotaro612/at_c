#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numbers>
#include <numeric>
#include <queue>
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

private:
  vector<E> bit;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, q;
  cin >> n >> q;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  int a_max = 500010;
  Bit<ll> bit(a_max + 1);
  dbg(a_max);
  Bit<ll> count_bit(a_max + 1);
  map<int, int> idx_v;
  rep(i, n) {
    bit.add(av[i], av[i]);
    count_bit.add(av[i], 1);
    idx_v[i] = av[i];
  }
  rep(i, q) {

    int t;
    cin >> t;
    if (t == 1) {
      ll x, y;
      cin >> x >> y;
      ll a = idx_v[x - 1];
      bit.add(a, -a);
      count_bit.add(a, -1);

      idx_v[x - 1] = y;
      bit.add(y, y);
      count_bit.add(y, 1);
    } else {
      ll l, r;
      cin >> l >> r;
      if (r <= l) {
        cout << l * n << endl;
        continue;
      }
      ll res = count_bit.sum_range(r, a_max + 1) * r;
      res += count_bit.sum(l) * l;
      res += bit.sum_range(l, r);
      cout << res << endl;
    }
  }

  return 0;
}
