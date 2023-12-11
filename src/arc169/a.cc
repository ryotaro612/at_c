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
void measure_depths(int node, int depth, vector<vector<int>> &g, vector<ll> &av,
                    vector<ll> &depths) {
  depths[depth] += av[node];
  for (auto child : g[node]) {
    measure_depths(child, depth + 1, g, av, depths);
  }
}
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<int> pv(n - 1);
  rep(i, n - 1) {
    cin >> pv[i];
    pv[i]--;
  }
  vector<vector<int>> g(n);
  rep(i, n - 1) { g[pv[i]].push_back(i + 1); }
  vector<ll> depths(n, 0);
  measure_depths(0, 0, g, av, depths);
  int non_zero_i = n - 1;
  while (non_zero_i > 0 && depths[non_zero_i] == 0)
    non_zero_i--;

  if (depths[non_zero_i] > 0) {
    cout << "+\n";
  } else if (depths[non_zero_i] < 0)
    cout << "-\n";
  else
    cout << "0\n";
  return 0;

  return 0;
}
