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
bool is_palindrome(string s) {
  int i = 0, j = s.size() - 1;

  while (i < j) {
    if(s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
int main() {
  int res = 0;
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = i + 1; j <= (int)s.size(); j++) {
      string sub = string(begin(s) + i, begin(s) + j);
      if (is_palindrome(sub))
        res = max(res, (int)size(sub));
    }
  }
  cout << res << endl;
  return 0;
}
