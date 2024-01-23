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
  string s, t;
  cin >> s >> t;
  if(s==t) {
    cout << 0 << endl;
    return 0;
  }
    
  int res = 0;
  int cost = 0;
  bool found = false;
  rep(i, n) {
    if (s[i] != t[i]) {
      if (s[i] == 'A') {
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
        if (cost)
          cost--;
        else {
          res++;
        }
      } else {
        res++;
        cost++;
      }
    }
    if (t[i] == 'A')
      found = true;
  }
   found = false;
  for(int i = n-1;i>=0;i--) {
    if(s[i] == 'B' && t[i] =='A') {
      if(!found) {
	cout << -1 << endl;
	return 0;
      }
    }
    if(t[i]=='B')
      found = true;
  }
  cout << res << endl;
  return 0;
}
