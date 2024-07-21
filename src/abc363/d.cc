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
ll my_pow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}
string sub(int keta, ll num) {
  dbg(keta, num);
  if (num <= 0)
    return "";

  if (keta == 1)
    return to_string(num - 1ll);
  if(keta == 0)
	return "";

  ll offset = 0;
  for (int i = 0; i <= 9; i++) {

    if (num <= offset + my_pow(10ll, (keta - 1ll) / 2ll)) {
      return to_string(i) + sub(keta - 2, num - offset) + to_string(i);
    }
    offset += my_pow(10ll, (keta - 1ll) / 2ll);
  }
  assert(false);
}
string solve(ll keta, ll num) {
  dbg(keta);
  ll offset = 0;

  for (int i = 1; i <= 9; i++) {
	dbg(offset);
    if (num <= offset + my_pow(10ll, (keta - 1ll) / 2ll)) {
      return to_string(i) + sub(keta - 2, num - offset) + to_string(i);
    }
    offset += my_pow(10ll, (keta - 1ll) / 2ll);
  }
  assert(false);
}
int main() {
  ll n;
  cin >> n;
  if (n <= 10) {
    cout << n - 1 << endl;
    return 0;
  }

  ll offset = 10ll;
  for (int keta = 2;; keta++) {
    ll add = 9ll;
	
    rep(j, (keta - 1ll) / 2ll) { add *= 10ll; }
    if (n <= offset + add) {
      cout << solve(keta, n - offset) << endl;
      return 0;
    }
    offset += add;
  }

  return 0;
}
