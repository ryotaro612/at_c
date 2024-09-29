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
  int n, q;
  string s;
  cin >> n >> q >> s;
  set<int> res;
  rep(i, n-2) {
	if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
	  res.insert(i);
  }
  dbg(res);
  rep(_, q) {
	int x;
	char c;
	cin >> x >> c;
	x--;
	if(s[x] == 'A') {
	  if(res.contains(x))
		res.erase(x);
	} else if(s[x]== 'B') {
	  if(res.contains(x-1))
		res.erase(x-1);
	} else if(s[x] == 'C') {
	  if(res.contains(x-2))
		res.erase(x-2);	  
	} else {
	  rep(j, 3) {
		if(res.contains(x-2+j))
		  res.erase(x-2+j);
	  }
	}
	dbg(res);
	s[x] = c;	
	if(c == 'A') {
	  if(x < n - 2 && s[x] == 'A' && s[x+1] =='B' && s[x+2] == 'C')
		res.insert(x);
	} else if(c == 'B') {
	  if(x && x < n - 1 && s[x-1] == 'A' && s[x] =='B' && s[x+1] == 'C')
		res.insert(x-1);	  
	} else if(c == 'C') {
	  if(x>1 && s[x-2] == 'A' && s[x-1] =='B' && s[x] == 'C')
		res.insert(x-2);
	} 

	cout << res.size() << endl;
  }
  return 0;
}
