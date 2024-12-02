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
  string s;
  cin >> s;
  int n = s.size();  
  if(n % 2) {
	cout << "No\n";
	return 0;
  }

  for(int i=1;i<= n/2;i++) {
	if(s[2*i-1] != s[2*i-2]) {
	  cout << "No\n";
	  return 0;
	}
  }
    map<char, int> mp;
  for(auto c: s) {
	mp[c]++;
  }
  for(auto [_, v]: mp) { 
	if(v !=2){
	  cout << "No\n";
	  return 0;
	}
  }
  cout << "Yes\n";
  return 0;
}
