#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #x << " = " << x   \
       << "\e[39m" << endl;
#else
#define dbg(x)
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

void solve(string a, int k, string before, set<int> used, ll &res) {
  dbg(before);
  if (size(before) == size(a)) {
    res = min(abs(stoll(before) - stoll(a)), res);
    return;
  }
  int d = a[size(before)] - '0';
  if ((int)size(used) < k || used.count(d)) {
    set<int> temp(used);
    temp.insert(d);
    before.push_back(d + '0');
    solve(a, k, before, temp, res);
    before.pop_back();
  }
  if (d < 9) {
    set<int> temp(used);
    if ((int)size(temp) < k)
      temp.insert(d + 1);
    auto iter = temp.upper_bound(d);
    if (iter != end(temp)) {
      string temp_before = string(before) + string(1, *iter + '0');
      if ((int)size(temp) < k)
        temp.insert(0);
      while (size(temp_before) < size(a))
        temp_before.push_back(*begin(temp) + '0');
      dbg(temp_before);
      res = min(res, abs(stoll(temp_before) - stoll(a)));
    }
  }
  if (d) {
    set<int> temp(used);
    if ((int)size(temp) < k)
      temp.insert(d - 1);
    auto iter = temp.lower_bound(d);
    if (iter != begin(temp)) {
      string temp_before = string(before) + string(1, *prev(iter) + '0');
      if ((int)size(temp) < k)
        temp.insert(9);
      while (size(temp_before) < size(a))
        temp_before.push_back(*rbegin(temp) + '0');
      dbg(temp_before);
      res = min(res, abs(stoll(temp_before) - stoll(a)));
    }
  }
}
int main() {

  ll a, res;
  int k;
  cin >> a >> k;
  res = a;
  ll i = 9;
  while (i <= a) {
    res = min(res, a - i);
    i *= 10ll;
    i += 9ll;
  }

  solve(to_string(a), k, "", {}, res);
  cout << res << endl;

  return 0;
}
