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
void traverse(int node, vector<vector<int>> &pm, vector<bool> &used, vector<int> &temp,
              vector<int> &res) {
  for (auto child : pm[node]) {
    if (!used[child]) {
      used[child] = true;
      dbg(child + 1); 
      traverse(child, pm, used, temp, res);
      res.push_back(child + 1);      
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> pm(n);
  rep(i, n) {
    int c;
    cin >> c;
    rep(j, c) {
      int p;
      cin >> p;
      pm[i].push_back(--p);
    }
  }
  vector<bool> used(n, false);
  vector<int> res, temp;
  used[0] = true;
  traverse(0, pm, used, temp, res);
  dbg(res);
  rep(i, size(res)) { cout << res[i] << " \n"[i == (int)size(res) - 1]; }
  return 0;
}
