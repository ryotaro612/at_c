#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)														\
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__ \
  << " = ";																\
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
map<ll, int> assoc(vector<ll> &xv, vector<ll> &lv, vector<ll> &rv) {
  set<ll> so;
  for(auto e: xv) {
	so.insert(e);
  }
  for(auto e: lv) {
	so.insert(e);
  }
    for(auto e: rv) {
	so.insert(e);
  }

  map<ll, int> mp;
  int cnt = 0;
  for(auto e: so) {
	mp[e]= cnt++;
  }
  return mp;
}
int main() {
  int n;
  cin >> n;
  vector<ll> xv(n), pv(n);
  rep(i, n)
	cin >> xv[i];
  rep(i, n)
	cin >> pv[i];
  int q;
  cin >> q;
  vector<ll> lv(q), rv(q);
  rep(i, q) {
	cin >> lv[i] >> rv[i];
  }

  map<ll, int> mp = assoc(xv, lv, rv);
  Bit<ll> bit(mp.size());
  rep(i, n) {
	bit.add(mp[xv[i]], pv[i]);
	dbg(mp[xv[i]]);
  }
  rep(i, q) {
	ll l = mp[lv[i]];
	ll r = mp[rv[i]];
	cout << bit.sum_range(l, r+1ll) << endl;
  }
  return 0;
}
