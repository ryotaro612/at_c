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

  vector<ll> xv(5, 0);
  rep(i, 5)
	cin>> xv[i];
  map<ll, vector<string>> mp;
  
  rep(i, 1<<5) {
	ll score = 0;
	string name;
	rep(j, 5) {
	  if((1<<j) & i) {
		score += xv[j];
		name.push_back('A' + j);
	  }
	}
	mp[score].push_back(name);
  }
  vector<string> res;
  for(auto [k, v]: mp) {
	sort(begin(v), end(v));
	reverse(begin(v), end(v));
	for(auto na: v)
	  res.push_back(na);
  }
  reverse(begin(res), end(res));
  for(auto e: res)
	cout << e << endl;
  
  return 0;
}
