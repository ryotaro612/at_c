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
  vector<string> sv(n);
  int height = 0;
  rep(i, n) {
	cin >> sv[i];
	height = max(height, (int)sv[i].size());
  }
  vector<string> res;
  rep(i, height) {
	string s;
	for(int j = n-1;j>=0;j--) {
	  if(i< (int)sv[j].size())
		s.push_back(sv[j][i]);
	  else
		s.push_back('*');
	}
	while(s.size() && s.back() == '*')
	  s.pop_back();
	if(s.size())
	  res.push_back(s);
  }
  rep(i, res.size()) {
	cout << res[i] << "\n";
  }
  
  return 0;
}
