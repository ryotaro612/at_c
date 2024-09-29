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
  int n;
  cin >> n;
  vector<int> hv(n);
  set<pair<int, int>> order;
  rep(i, n) {
    cin >> hv[i];
    order.insert({-hv[i], -i});
  }

  vector<int> res(n, 0);
  set<int> done;
  while (order.size()) {
    auto [h, pos] = *begin(order);
    h = -h;
    pos = -pos;
    order.erase(begin(order));
    dbg(h, pos);
    if (done.size() == 0) {
      res[0] += 1;
      res[pos] -= 1;
    } else {
      auto iter = done.upper_bound(pos);
      if (iter == begin(done)) {
        res[0] += 1;
        res[pos] -= 1;

      } else {
        res[*prev(iter)] += 1;
        res[pos] -= 1;
      }
    }
	done.insert(pos);
	dbg(res);
  }
  for (int i = 1; i < n; i++) {
    res[i] += res[i - 1];
  }

  rep(i, n) { cout << res[i] << " \n"[i == n - 1]; }

  return 0;
}
