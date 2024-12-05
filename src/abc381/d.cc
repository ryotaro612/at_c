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
  vector<int> av(n);
  rep(i, n) { cin >> av[i]; }
  map<int, int> mp;
  int res = 0;
  for (int left = 0, right = 0; left < n;) {
    right = max(right, left);
    while (right < n - 1 && av[right] == av[right + 1] && mp[av[right]] == 0) {
      mp[av[right]] += 2;
      right += 2;
    }
    dbg(left, right);
    res = max(res, right - left);
    if (left < n - 1 && mp[av[left]] == 2 && av[left] == av[left + 1])
      mp[av[left]] = 0;
    left += 2;
  }
  mp = map<int, int>();
  for (int left = 1, right = 0; left < n;) {
    right = max(right, left);
    while (right < n - 1 && av[right] == av[right + 1] && mp[av[right]] == 0) {
      mp[av[right]] += 2;
      right += 2;
    }
    res = max(res, right - left);
    dbg(left, right);
    if (left < n - 1 && mp[av[left]] == 2 && av[left] == av[left + 1])
      mp[av[left]] = 0;
    left += 2;
  }
  cout << res << endl;
  return 0;
}
