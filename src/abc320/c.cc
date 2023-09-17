#include <algorithm>
#include <bits/stdc++.h>
#include <variant>
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
  int m;
  cin >> m;
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  s[0] = s[0] + s[0] + s[0];
  s[1] = s[1] + s[1] + s[1];
  s[2] = s[2] + s[2] + s[2];
  int res = 1 << 30;
  rep(i, 10) {
    char c = '0' + i;
    vector<int> order = {0, 1, 2};
    do {
      int slot_i = 0;
      rep(j, 3*m) {
	if(s[order[slot_i]][j] == c) {
	  slot_i++;
	}
	if(slot_i == 3) {
	  res = min(res, j);
	  break;
	}
      }
      
    } while(next_permutation(begin(order),  end(order)));
  }
  if (res == (1 << 30)) {
    cout << -1 << endl;
  } else
    cout << res << endl;
  return 0;
}
