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
  vector<pair<int, int>> abs(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if (b < a)
      swap(a, b);
    abs[i] = {a, b};
  }
  sort(begin(abs), end(abs));
  vector<int> stk;
  for (auto [a, b] : abs) {
    dbg(a, b, stk);
    while (stk.size() && stk.back() < a)
      stk.pop_back();
    if(stk.size() && stk.back() < b) {
      cout << "Yes\n";
      return 0;
    }
    stk.push_back(b);
  }
  cout << "No\n";

  return 0;
}
