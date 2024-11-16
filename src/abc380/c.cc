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
  int n,k;
  string s;  
  cin >> n >> k >> s;
  vector<int> pos;
  vector<int> pos_end;
  for(int i = 0;i<n;) {
	if(s[i] == '0') {
	  i++;
	  continue;
	} else {
	  pos.push_back(i);
	  while(i< n && s[i] == '1')
		i++;
	  pos_end.push_back(i);
	}
  }
  dbg(pos);
  dbg(pos_end);
  string res = string(begin(s), begin(s) + pos_end[k-2]);
  dbg(res);
  res += string(begin(s) + pos[k-1], begin(s) + pos_end[k-1]);
  dbg(res);
  res += string(begin(s) + pos_end[k-2], begin(s) + pos[k-1]);
  dbg(res);
  res += string(begin(s) + pos_end[k-1], end(s));
  cout << res << endl;
  
  return 0;
}
