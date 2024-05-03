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
  int n, q;
  cin >> n >> q;
  vector<int> xv(q);
  vector<ll> sum(q + 1, 0);
  set<int> st;
  vector<vector<int>> pos(n);
  rep(i, q) {
    cin >> xv[i];
    if (st.contains(xv[i]))
      st.erase(xv[i]);
    else
      st.insert(xv[i]);

    sum[i + 1] += sum[i] + size(st);
    pos[xv[i] - 1].push_back(i);
  }
  dbg(sum);
  // 1 2 1 2
  dbg(pos);

  rep(i, n) {
    ll res = 0;
    for (int j = 0; j < (int)pos[i].size();) {
      if (j < (int)pos[i].size() - 1) {
        res += sum[pos[i][j + 1]] - sum[pos[i][j]];
        j += 2;
      } else {
        res += sum[q] - sum[pos[i][j]];
        j += 1;
      }
    }
    cout << res << " \n"[i == n - 1];
  }

  return 0;
}
