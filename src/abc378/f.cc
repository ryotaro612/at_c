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

class UnionFind {
public:
  vector<int> par;
  /**
   *  グループの総数
   */
  UnionFind(int n) { par = vector<int>(n, -1); }

  int find_root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = find_root(par[a]);
  }

  int is_same_group(int a, int b) { return find_root(a) == find_root(b); }

  void unite(int a, int b) {
    if (is_same_group(a, b))
      return;
    int root_a = find_root(a), root_b = find_root(b);
    if (group_size(root_a) > group_size(b)) {
      par[root_a] += par[root_b];
      par[root_b] = root_a;
    } else {
      par[root_b] += par[root_a];
      par[root_a] = root_b;
    }
  }
  int group_size(int a) { return -par[find_root(a)]; }
  /**
   * グループの総数を返す。
   */
  int count_groups() {
    unordered_set<int> groups;
    rep(i, par.size()) { groups.insert(find_root(i)); }
    return groups.size();
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    dbg(u, v);
  }
  vector<int> two;
  UnionFind uf(n);
  rep(i, n) {
    if (g[i].size() == 2) {
      two.push_back(i);
      continue;
    } else if (g[i].size() == 3) {
	  for(int neighbor: g[i]) {
		if(g[neighbor].size() == 3) {
		  uf.unite(neighbor, i);
		}
	  }
	  continue;
    }
  }
  map<int, ll> mp;
  for(auto t: two) {
	for(auto neighbor: g[t]) {
	  if(g[neighbor].size() == 3) {
		mp[uf.find_root(neighbor)]++;
	  }
	}
  }
  ll res = 0;
  for(auto [_, v]: mp) {
	res += v*(v-1ll)/2ll;
  }
  cout << res << endl;

  return 0;
}
