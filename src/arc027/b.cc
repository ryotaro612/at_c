#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

class UnionFind {
public:
  vector<int> par;
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
  int group_size(int a) { return -find_root(a); }
};

int to_idx(char c) {
  if ('A' <= c && 'Z' >= c)
    return c - 'A' + 10;
  return c - '0';
}

void normalize(string &s1, string &s2) {
  int n = s1.size();
  UnionFind uf(36);
  rep(i, n) uf.unite(to_idx(s1[i]), to_idx(s2[i]));
  map<int, char> mp;
  rep(i, 10) { mp[uf.find_root(i)] = i + '0'; }
  rep(i, n) {
    int root_i = uf.find_root(to_idx(s1[i]));
    if (mp.find(root_i) == mp.end()) {
      s1[i] = uf.find_root(to_idx(s1[i])) - 10 + 'A';
    } else
      s1[i] = mp[root_i];
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  normalize(s1, s2);
  // cout << s1 << endl;
  UnionFind uf(26);
  rep(i, n) {
    if ('A' <= s1[i] && s1[i] <= 'Z') {
      uf.unite(s1[i] - 'A', s2[i] - 'A');
    }
  }
  ll res = 1ll;
  set<char> used;
  rep(i, n) {
    if (i) {
      if ('A' <= s1[i] && s1[i] <= 'Z') {
        if (used.find(s1[i]) == used.end()) {
          used.insert(s1[i]);
          res *= 10ll;
        } else {
          // nop
        }
      } else {
        // nop
      }
    } else {
      if ('A' <= s1[i] && s1[i] <= 'Z') {
        used.insert(s1[0]);
        res *= 9ll;
      } else {
        // nop;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
