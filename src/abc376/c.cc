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
  int n;
  cin >> n;
  vector<ll> av(n), bv(n-1);
  rep(i, n)
	cin >> av[i];
  rep(i, n-1)
	cin >> bv[i];
 
  sort(begin(av), end(av));
  reverse(begin(av), end(av));
  sort(begin(bv), end(bv));
  reverse(begin(bv), end(bv));
  ll skip = -1ll;
  int a_i=0, b_i = 0;
  while(a_i < n && b_i < n-1) {
	if(av[a_i] <= bv[b_i]) {
	  a_i++;
	  b_i++;
	} else if(skip < 0){
	  skip = av[a_i];
	  a_i++;
	} else {
	  cout << -1 << endl;
	  return 0;
	}
  }
  if(skip == -1)
	skip = av[n-1];
  cout << skip << endl;
  return 0;
}
