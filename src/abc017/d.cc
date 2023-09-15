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

class Bit {
public:
  Bit(int size) { bit.resize(size + 1, 0); }

  ll sum(int to) {
    ll res = 0;
    while (to) {
      res += bit[to];
      res %= mod;
      to -= to & (-to);
    }
    return res;
  }

  void add(int i, ll v) {
    i++;
    while (i < (int)bit.size()) {
      bit[i] += v;
      bit[i] %= mod;
      i += i & (-i);
    }
  }

private:
  vector<ll> bit;
  const ll mod = 1000000007ll;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> fv(n);
  rep(i, n) cin >> fv[i];
  const ll mod = 1000000007ll;
  Bit bit(n + 1);
  bit.add(0, 1);
  vector<ll> prev(m + 1, -1);
  ll offset = -1;
  rep(i, n) {
    offset = max(offset, prev[fv[i]]);
    if (offset == -1) {
      ll v = bit.sum(i + 1);
      dbg(i, v);
      bit.add(i + 1, v);
    } else {
      ll v = bit.sum(i + 1) - bit.sum(offset + 1);
      if(v < 0)
	v += mod;
      dbg(i, v);      
      bit.add(i + 1, v);
    }
    prev[fv[i]] = i;
  }
  ll res = bit.sum(n+1) - bit.sum(n);
  if(res < 0)
    res += mod;
  cout << res << endl;
  return 0;
}
/*
  3 -> 1
  
 */
