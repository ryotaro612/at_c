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
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  map<int, set<int>> st;
  rep(i, n) {
	st[i].insert(i);
  }
  rep(_, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
	  dbg(u, v);
	  set<int> a_st = st[uf.find_root(u)];
	  set<int> b_st = st[uf.find_root(v)];	  
	  set<int> next_st;
	  auto iter = end(a_st);
	  rep(_, 11) {
		if(iter == begin(a_st)) {
		  break;
		}
		iter = prev(iter);
		next_st.insert(*iter);
	  }
	  iter = end(b_st);
	  rep(_, 11) {
		if(iter == begin(b_st)) {
		  break;
		}
		iter = prev(iter);
		next_st.insert(*iter);
	  }
	  uf.unite(u, v);
	  st[uf.find_root(u)] = next_st;

    } else {
      int u, k;
      cin >> u >> k;
	  u--;
	  set<int> temp = st[uf.find_root(u)];
	  dbg(temp);
      if ((int)temp.size() < k)
        cout << -1 << endl;
      else {
		auto iter = end(temp);
		rep(_, k) {
		  iter = prev(iter);
		}
		cout << *iter + 1<< endl;
      }
    }
  }
  return 0;
}
