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
  vector<int> av(5);
  rep(i, 4) {
		cin >> av[i];
  }
  for(int i = 1;i<=13;i++) {
	vector<int> temp(av);
	temp[4] = i;
	sort(temp.begin(), temp.end());
	if(temp[0] == temp[1] && temp[0] != temp[2] && (temp[2] == temp[3] && temp[3] == temp[4])) {
	  dbg(temp);
	  cout << "Yes\n";
	  return 0;
	}
	reverse(temp.begin(), temp.end());
	if(temp[0] == temp[1] && temp[0] != temp[2] && (temp[2] == temp[3] && temp[3] == temp[4])) {
	  dbg(temp);
	  cout << "Yes\n";
	  return 0;
	}	
  }
  cout << "No\n";
  return 0;
}
