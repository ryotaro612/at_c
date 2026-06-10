#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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
  pair<int, int> pos;
  cin >> n >> pos.first >> pos.second;
  set<pair<int, int>> st;

  pair<int, int> smoke = {0, 0};
  st.insert(smoke);
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'N') {
      pos.first++;
      smoke.first++;
      ;
    } else if (c == 'W') {
      pos.second++;
      smoke.second++;
    } else if (c == 'S') {
      pos.first--;
      smoke.first--;
    } else {
      pos.second--;
      smoke.second--;
    }

    st.insert(smoke);
    // dbg(st);
    if (st.count(pos)) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << endl;
  return 0;
}
