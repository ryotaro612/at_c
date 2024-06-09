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
void check_loop(int i, vector<int> &av, vector<int> &loop, set<int> &visit) {
  if (loop[i] != -1)
    return;
  if (visit.contains(i)) {
    loop[i] = 1;
    for (int j = av[i]; j != i; j = av[j]) {
      loop[j] = 1;
    }
    return;
  }

  visit.insert(i);
  check_loop(av[i], av, loop, visit);
  if (loop[i] != 1)
    loop[i] = 0;
  return;
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

ll solve(int i, UnionFind &uf, vector<int> &loop, vector<int> &av) {
  dbg(i);
  if (loop[i] == 1)
    return uf.group_size(i);

  return solve(av[i], uf, loop, av) + 1ll;
}

int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) {
    cin >> av[i];
    av[i]--;
  }
  vector<int> loop(n, -1);
  set<int> visit;
  dbg("doge");
  rep(i, n) { check_loop(i, av, loop, visit); }
  dbg(loop);
  UnionFind uf(n);
  rep(i, n) {
    if (loop[i] == 1 && loop[av[i]] == 1) {
      uf.unite(i, av[i]);
    }
  }
  dbg("hi");
  vector<ll> res(n, 0);
  ll result = 0;
  rep(i, n) {
    res[i] = solve(i, uf, loop, av);
    result += res[i];
  }

  cout << result << endl;

  return 0;
}
