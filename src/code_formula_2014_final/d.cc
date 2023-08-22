#include <algorithm>
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
struct interval {
  int l, r, id;
  interval() {}
  interval(const int &pl, int &pr, int pid) : l(pl), r(pr), id(pid) {}
  bool operator<(const interval &I) const {
    return make_tuple(l, r) < make_tuple(I.l, I.r);
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> hv(n), prefix_sum(n + 1, 0);
  rep(i, n) {
    cin >> hv[i];
    prefix_sum[i + 1] += hv[i] + prefix_sum[i];
  }
  vector<interval> iv(n);
  rep(i, n) cin >> iv[i].id >> iv[i].l >> iv[i].r;
  sort(begin(iv), end(iv));

  vector<int> dp(n, hv[0]);

  rep(i, n) {
    rep(j, i) {
      if (iv[j].r <= iv[i].l)
        dp[i] = max(dp[i], dp[j] + hv[0]);
    }
    int cnt = 0;
    int left = iv[i].l;
    for (int j = i - 1; j >= 0; j--) {
      if (iv[j].r <= left && iv[j].id == iv[i].id) {
        cnt++;
        left = iv[j].l;
        dp[i] = max(dp[i], dp[j] + prefix_sum[cnt + 1] - hv[0]);
      }
    }
  }

  cout << *max_element(begin(dp), end(dp)) << endl;
  return 0;
}
