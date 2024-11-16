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
int rec(vector<int> av) {
  sort(begin(av), end(av));
  if(av.size() == 0)
	return 0;
  pair<int, int> x = {-1, -1};
  vector<int> bv;
  rep(i, av.size()) {
	if(x.first == -1 && i < (int) av.size() -1 && av[i] == av[i+1]) {
	  x = {i, i+1};
	}
	if(i != x.first && i != x.second) {
	  bv.push_back(av[i]);
	}
  }
  if(x.first == -1)
	return 0;
  
  return 1 + rec(bv);
}
int main() {
  vector<int> av(4);
  rep(i, 4) cin >> av[i];
  cout << rec(av) << endl;
  
  return 0;
}
