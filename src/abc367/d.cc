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
  ll n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  vector<ll> sum_v(n * 2, 0);
  ll sum = 0;
  rep(i, 2 * n) {
    sum_v[i] = sum;
    sum += av[i%n];
	sum %= m;
  }
  vector<ll> bv(m, 0);
  rep(i, n) {
	bv[sum_v[i]]++;
  }
  ll res = 0;
  for(int i = n;i<2*n;i++) {
	bv[sum_v[i-n]]--;
	res += bv[sum_v[i]];
	bv[sum_v[i]]++;
  }
  cout << res << endl;
  return 0;
}
