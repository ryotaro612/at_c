#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class UnionFind {
public:
  UnionFind(int n) { par = vector<int>(n, -1); }
  int find_root(int i) {
    if (par[i] < 0)
      return i;
    return par[i] = find_root(par[i]);
  }
  bool same_group(int a, int b) { return find_root(a) == find_root(b); }
  void unite(int a, int b) {
    if (same_group(a, b))
      return;

    int root_a = find_root(a), root_b = find_root(b);

    if (par[root_a] < par[root_b]) {
      par[root_a] += par[root_b];
      par[root_b] = root_a;
    } else {
      par[root_b] += par[root_a];
      par[root_a] = root_b;
    }
  }

private:
  vector<int> par;
};

struct Edge {
  int node1, node2, cost;
};

struct Query {
  int node1, node2, cost, index;
};

vector<string> solve(int n, int m, int q, vector<int> &a, vector<int> &b,
                     vector<int> &c, vector<int> &u, vector<int> &v,
                     vector<int> &w) {
  vector<Edge> edges(m);
  rep(i, m) { edges[i] = {a[i] - 1, b[i] - 1, c[i]}; }
  sort(edges.begin(), edges.end(),
       [](const Edge &a, const Edge &b) { return a.cost < b.cost; });

  vector<Query> queries(q);
  rep(i, q) { queries[i] = {u[i] - 1, v[i] - 1, w[i], i}; }
  sort(queries.begin(), queries.end(),
       [](const Query &a, const Query &b) { return a.cost < b.cost; });
  
  UnionFind uf(n);
  vector<string> res(q, "No");
  int query_index = 0;
  rep(i, m) {
    //cout << "query_index: " << query_index << endl;
    //cout << "i: " << i << endl;
    while (query_index < q && queries[query_index].cost < edges[i].cost) {
      //cout << queries[query_index].node1 << " " << queries[query_index].node2 << endl;
      if (!uf.same_group(queries[query_index].node1,
                         queries[query_index].node2)) {
        //cout << "foo" << endl;
        res[queries[query_index].index] = "Yes";
      }
      query_index++;
    }
    //cout << "@"<< endl;
    if (!uf.same_group(edges[i].node1, edges[i].node2)) {
      uf.unite(edges[i].node1, edges[i].node2);
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(m), b(m), c(m);
  rep(i, m) { cin >> a[i] >> b[i] >> c[i]; }
  vector<int> u(q), v(q), w(q);
  rep(i, q) { cin >> u[i] >> v[i] >> w[i]; }
  vector<string> res = solve(n, m, q, a, b, c, u, v, w);
  for (auto &e : res)
    cout << e << endl;
  return 0;
}
#endif
