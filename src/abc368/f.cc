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

vector<ll> compute_divisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i)
        res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int calc_grundy(int n, map<int, int> &cache) {
  if (cache.count(n))
    return cache[n];

  auto divisors = compute_divisors(n);
  set<int> ng;
  rep(i, divisors.size() - 1) { ng.insert(calc_grundy(divisors[i], cache)); }
  for (int res = 0;; res++) {
    if (!ng.count(res))
      return cache[n] = res;
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  map<int, int> cache;
  rep(i, n) cin >> av[i];
  ll check = 0;
  rep(i, n) { check ^= calc_grundy(av[i], cache);}
  if(check) {
	cout << "Anna\n";
  } else
	cout << "Bruno\n";

  return 0;
}
