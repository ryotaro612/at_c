#include <algorithm>
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
  int n, mg, mh;
  cin >> n >> mg;
  set<pair<int, int>> g, h;
  rep(i, mg) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
	g.insert({min(u, v), max(u, v)});
  }
  cin >> mh;
  rep(i, mh) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
	h.insert({min(a, b), max(a, b)});
  }

  vector<vector<int>> am(n, vector<int>(n, 0));
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      cin >> am[i][j];
      am[j][i] = am[i][j];
    }
  }

  vector<int> order(n);
  rep(i, n) order[i] = i;
  ll res = 1000000000000000;
  do {

	set<pair<int, int>> converted;
	for(auto [x, y]: g) {
	  converted.insert({min(order[x], order[y]), max(order[x], order[y])});
	}
	ll cand = 0;	
	for(auto [x, y]: converted) {
	  if(!h.contains({x, y})) {
		cand += am[x][y];
	  }
	}
	for(auto [x, y]: h) {
	  if(!converted.contains({x, y})) {
		cand += am[x][y];
	  }
	}	
	res = min(res, cand);
	
  } while(next_permutation(begin(order), end(order)));

  cout << res << endl;
  return 0;
}
