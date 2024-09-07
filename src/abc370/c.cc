#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)														\
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__ \
  << " = ";																\
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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  vector<string> res;
  while(s != t) {
	vector<string> cands;
	rep(i, n) {
	  if(s[i] != t[i]) {
		string cand = string(s);
		cand[i] = t[i];
		cands.push_back(cand);
	  }
	}
	sort(begin(cands), end(cands));

	res.push_back(cands[0]);
	s = cands[0];
  }
  cout << res.size() << endl;
  rep(i, res.size()) {
	cout << res[i] << endl;
  }
  return 0;
}
