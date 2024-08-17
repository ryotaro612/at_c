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

void rec(vector<vector<int>> &res, int i, vector<int> &temp, vector<int> &rv,
         int k) {
  int n = rv.size();
  if (n == i) {
    int sum = 0;
    for (auto e : temp)
      sum += e;
    if (sum % k == 0) {
      res.push_back(vector<int>(temp));
    }
    return;
  }
  for (int r = 1; r<= rv[i]; r++) {
	temp.push_back(r);
	rec(res, i+1, temp, rv, k);
	temp.pop_back();
  }
}
int main() {

  int n, k;
  cin >> n >> k;
  vector<int> rv(n);
  rep(i, n) cin >> rv[i];
  vector<vector<int>> res;
  vector<int> temp;
  rec(res, 0, temp, rv, k);

  sort(begin(res), end(res));
  for (auto v : res) {
    rep(i, v.size()) { cout << v[i] << " \n"[i == (int)v.size() - 1]; }
  }
  return 0;
}
