#include <bits/stdc++.h>
#include <string>
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
ll is_hebi(ll n) {
  string s = to_string(n);
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[0] <= s[i])
      return 0;
  }
  return 1;
}

ll pattern2(ll r) {
  string s = to_string(r);
  int keta = s.size();
  vector<ll> digits(keta);
  rep(i, keta) { digits[i] = s[i] - '0'; }

  ll res = 0;
  for (int k = 1; k <= keta - 1; k++) {

    // digits[i] < digits[0]
    res += min(digits[0], digits[k]) * my_pow(digits[0], keta - k - 1);
    if (digits[0] <= digits[k]) { 
      break;	  
	}	
  }
  return res;
}

ll pattern3(ll r) {
  string s = to_string(r);
  int keta = s.size();
  vector<ll> digits(keta);
  rep(i, keta) { digits[i] = s[i] - '0'; }
  ll res = 0;
  for (int i = 1; i < digits[0]; i++) {
    res += my_pow(i, keta - 1);
  }
  return res;
}

ll pattern4(ll r) {
  string s = to_string(r);
  int keta = s.size();
  vector<ll> digits(keta);
  rep(i, keta) { digits[i] = s[i] - '0'; }
  ll res = 0;
  for (int k = 1; k < keta; k++) {
    for (int i = 1; i < 10; i++) {
      res += my_pow(i, k - 1);
    }
  }
  return res;
}

ll solve(ll r) {
  string s = to_string(r);
  int keta = s.size();
  vector<ll> digits(keta);
  rep(i, keta) { digits[i] = s[i] - '0'; }

  ll res = is_hebi(r);

  res += pattern2(r);
  res += pattern3(r);
  res += pattern4(r);

  return res;
}

int main() {

  ll l, r;
  cin >> l >> r;
  // dbg(solve(20));
  cout << solve(r) - solve(l - 1) << endl;
  return 0;
}
