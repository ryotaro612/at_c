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

ll res = 10000000000000ll;
void traverse(int perent, int node,  vector<vector<int>> &tree) {
  dbg(node);
  int n = tree.size();
  vector<ll> aa(tree[node].size());
  rep(i, aa.size()) {
	aa[i] = (tree[tree[node][i]].size() - 1);
  }
  sort(begin(aa), end(aa));

  rep(i, aa.size()) {
	ll keep = tree[node].size() - i + aa[i] * (tree[node].size() - i);
	res = min(res, n-1-keep);
  }

  for(auto child: tree[node]) {
	if(child == perent) continue;
	traverse(node, child, tree);
  }
  
  
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    tree[u - 1].push_back(v - 1);
    tree[v - 1].push_back(u - 1);
  }

  traverse(-1, 0,  tree);
  cout << res << endl;

  return 0;
}
