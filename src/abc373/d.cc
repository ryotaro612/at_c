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
void dig(int u, vector<bool> &done, vector<ll> &weight,  vector<vector<pair<ll, int>>> &g, vector<vector<pair<ll, int>>> &rev) {

  for(auto [w, v]: g[u]) {
	if(done[v])
	  continue;
	weight[v] = w + weight[u];
	done[v] = true;
	dig(v, done, weight, g, rev);
  }
  for(auto [w, v]: rev[u]) {
	if(done[v])
	  continue;
	weight[v] =weight[u] - w;
	done[v] = true;
	dig(v, done, weight, g, rev);
  }  
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> g(n), rev(n);
  rep(i, m) {
	int u, v;
	ll w;
	cin >> u >> v >> w;
	u--;
	v--;
	g[u].push_back({w, v});
	rev[v].push_back({w, u});
  }
  vector<ll> weight(n, 0);
  vector<bool> done(n, false);
  rep(u, n) {
	dig(u, done, weight, g, rev);
  }

  rep(i, n) {
	cout << weight[i] << " \n"[i==n-1];
  }
  rep(u, n) {

	for(auto [w, v]: g[u]) {
	  dbg(u, v);
	  assert(weight[v] - weight[u] == w);
	}
  }  
  return 0;
}
