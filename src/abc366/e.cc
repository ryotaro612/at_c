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

vector<ll> calc_sum(vector<ll> &xv, ll d) {
  vector<ll> result(2ll * 2000010, 0);
  sort(begin(xv), end(xv));
  ll size = result.size();
  ll left = -2000000;
  ll right = 2000000;

  for (auto x : xv) {
    result[(left + size) % size] += abs(left - x);
  }
  vector<ll> res;
  if(result[(left + size) % size] <= d)
	res.push_back(result[(left + size) % size]);
  
  int j = 0;
  for (ll i = left + 1ll; i <= right; i++) {
    while (j < (int)xv.size() && xv[j] < i) {
      j++;
    }
    result[(i + size) % size] =
        result[(i - 1 + size) % size] + j - ((ll)xv.size() - j);

	if(result[(i + size) % size]<=d)
	   res.push_back(result[(i + size) % size]);
  }

  sort(begin(res), end(res));
  return res;
}
int main() {
  ll n, d;
  cin >> n >> d;
  vector<ll> xv(n), yv(n);
  rep(i, n) { cin >> xv[i] >> yv[i]; }
  vector<ll> xsum = calc_sum(xv, d), ysum = calc_sum(yv, d);
  //dbg(xsum);
  dbg(xsum);
  ll res = 0;
  ll i = 0;
  reverse(begin(xsum), end(xsum));
  for (auto x : xsum) {
    while (i < (int)ysum.size() && x + ysum[i] <= d)
      i += 1;
    res += i;
  }
  cout << res << endl;
  // vector<ll> xsum(bound * 2, 0), ysum(bound * 2);
  return 0;
}
