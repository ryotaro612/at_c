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
  ll h, w, m;
  cin >> h >> w >> m;
  vector<int> tv(m), av(m), xv(m);
  rep(i, m) {
    cin >> tv[i] >> av[i] >> xv[i];
    av[i]--;
  }
  vector<bool> used_rows(h, false), used_cols(w, false);
  ll avail_rows = h, avail_cols = w;
  map<int, ll> cnt;
  for (int i = m - 1; i >= 0; i--) {
    if (tv[i] == 1) {
      if(!used_rows[av[i]]) {
	used_rows[av[i]] = true;
	cnt[xv[i]] += avail_cols;
	avail_rows--;
      }
    } else {
      if(!used_cols[av[i]]) {
	used_cols[av[i]] = true;
	cnt[xv[i]] += avail_rows;
	avail_cols--;
      }      
    }
  }
  cnt[0] += avail_rows * avail_cols;
  vector<pair<ll, ll>> result;
  for(auto [c, num]: cnt) {
    if(num)
      result.push_back({c, num});
  }
  cout << result.size() << endl;
  for (auto [color, num] : result) {
    cout << color << " " << num << endl;
  }
  return 0;
}
