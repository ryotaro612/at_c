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
  int k;
  string s;
  string t;
  cin >> k >> s >> t;
  if (s == t) {
    cout << "Yes\n";
    return 0;
  }
  if (abs((int)s.size() - (int)t.size()) > 1) {
    cout << "No\n";
    return 0;
  }
  int n = s.size();

  if (s.size() == t.size()) {
    int diff = 0;
    rep(i, n) {
      if (s[i] != t[i]) {
        diff++;
      }
    }
    if (diff <= 1)
      cout << "Yes\n";
    else
      cout << "No\n";
    return 0;
  }
  if (s.size() > t.size()) {
    swap(s, t);
  }
  n = s.size();
  dbg("hi");  
  for (int i = 0, j = 0; i < n;) {
	dbg(i, j);
	if (s[i] == t[j]) {
	  i++;
	  j++;
	} else if(i == j) {
	  j++;
	} else {
	  cout << "No\n";
	  return 0;
	}
  }
  cout << "Yes\n";
  return 0;
}
