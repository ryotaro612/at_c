#include <bits/stdc++.h>
#include <string>
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
  int k;
  cin >> k;
  vector<ll> res;
  queue<ll> que;
  que.push(0);
  while (que.size()) {
    res.push_back(que.front());
    string s = to_string(que.front());
    if (s[0] != '9') {
      string temp = s;
      temp[0] = s[0] + 1;
      dbg(temp);
      que.push(stoll(temp));
      que.push(stoll(string(1, (s[0] + 1)) + s));
    }
    que.pop();
  }
  sort(begin(res), end(res));
  dbg(res);
  cout << res[k] << endl;
  return 0;
}
