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
  string s;
  cin >> s;
  string stk;
  for (int i = s.size() - 1; i >= 0; i--) {
    char c = s[i];
    stk.push_back(c);
    int n = stk.size();
    if (stk.size() > 2 && stk[n - 1] == 'A' && stk[n - 2] == 'B' && stk[n - 3] == 'C') {
      dbg("doge");
      stk.pop_back();
      stk.pop_back();
      stk.pop_back();
    }
    dbg(stk);
  }
  reverse(begin(stk), end(stk));
  cout << stk << endl;
  return 0;
}
