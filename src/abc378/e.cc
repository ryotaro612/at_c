#include <bits/stdc++.h>
#include <queue>
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
  int n, m;
  cin >> n >> m;
  vector<ll> av(n), s(n+1, 0);
  Bit<ll> bit(m+1);
  rep(i, n) {
	cin >>av[i];
	s[i+1] += av[i] + s[i];
	s[i+1] %= m;
  }
  ll res = 0;
  ll ss = 0;
  dbg(s);
  rep(i, n) {
	dbg(i);
	ll delta = (ll)(i+1) * s[i+1] - ss + m * (bit.sum(m) - bit.sum(s[i+1]+1));
	dbg(delta);
	res += delta;
	bit.add(s[i+1],1);
	ss += s[i+1];
  }

  cout << res << endl;

  return 0;
}
