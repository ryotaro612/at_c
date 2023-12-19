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

struct Range {
  int left, right;
  map<int, int> freq;
};

int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  ll res = 0;
  rep(i, n) { cin >> av[i]; }
  vector<int> stack;
  for (ll i = n - 1; i >= 0; i--) {

    stack.push_back(i);
    int next = 1;
    while (!stack.empty() && av[stack.back()] == next) {
      stack.pop_back();
      next++;
    }
    int right = n;
    if (stack.size())
      right = stack.back();

    res += right - i;
  }

  cout << res << endl;
  return 0;
}
