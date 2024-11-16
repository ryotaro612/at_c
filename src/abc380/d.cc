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
  int q;
  cin >> s >> q;
  vector<char> res;
  rep(i, q) {
    ll k;
    cin >> k;
    if (k <= (int)s.size()) {
      res.push_back(s[k - 1]);
      continue;
    }
    int cnt = 1;
    ll size = s.size();
    while (size < k) {
      size += size;
      cnt++;
    }
    dbg(i, k);	
    int rep = 0;
    while (k > (int)s.size()) {
	  while(k <= size)
		size /= 2ll;
      k -= size;
      rep++;
    }

    dbg(k, cnt, rep);
    if (rep % 2) {
      if ('a' <= s[k - 1] && s[k - 1] <= 'z') {
        res.push_back(toupper(s[k - 1]));
      } else {
        res.push_back(tolower(s[k - 1]));
      }
    } else {
      res.push_back(s[k - 1]);
    }
  }
  rep(i, q) { cout << res[i] << " \n"[q - 1 == i]; }
  return 0;
}
