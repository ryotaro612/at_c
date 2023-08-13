#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG

#endif
#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int recur_depth = 0;
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  {                                                                            \
    ++recur_depth;                                                             \
    auto x_ = x;                                                               \
    --recur_depth;                                                             \
    cerr << string(recur_depth, '\t') << "\e[91m" << __func__ << ":"           \
         << __LINE__ << "\t" << #x << " = " << x_ << "\e[39m" << endl;         \
  }
#else
#define dbg(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type
operator<<(Ostream &os, const Cont &v) {
  os << "[";
  for (auto &x : v) {
    os << x << ", ";
  }
  return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}

#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif
// g++ -fdiagnostics-color=always -g -O0 --std=c++20 -Wall
// -fsanitize=undefined,address
int main() {
  string s = "3."
             "14159265358979323846264338327950288419716939937510582097494459230"
             "78164062862089986280348253421170679";
  int n;
  cin >> n;
  vector<int> a = {1, 2};
  set<int> b = {3, 45};
  map<int, string> mp;
  mp[1] = "doge";
  cout << string(begin(s), begin(s) + 2 + n) << endl;

  return 0;
}
