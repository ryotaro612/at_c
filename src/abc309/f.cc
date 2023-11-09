#include <bits/stdc++.h>
#include <limits>
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

class Tree {
public:
  Tree(int n) {
    int i = 1;
    while (i < n)
      i *= 2;
    tree.resize(i * 2 - 1, numeric_limits<int>::max());
  }

  void update(int i, int v) {
    i += (tree.size() + 1) / 2 - 1;
    tree[i] = v;
    while (i > 0) {
      i = (i - 1) / 2;
      tree[i] = min(tree[i * 2 + 1], tree[i * 2 + 2]);
    }
  }
  int query(int left, int right) {
    return query(left, right, 0, 0, (tree.size() + 1) / 2);
  }

private:
  vector<int> tree;

  int query(int left, int right, int root, int l, int r) {
    if (r <= left || right <= l)
      return numeric_limits<int>::max();
    if (left <= l && r <= right)
      return tree[root];

    int cand1 = query(left, right, root * 2 + 1, l, (l + r) / 2);
    int cand2 = query(left, right, root * 2 + 2, (l + r) / 2, r);
    return min(cand1, cand2);
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> triplets(n);
  set<ll> values;
  rep(i, n) {
    vector<ll> t(3);
    cin >> t[0] >> t[1] >> t[2];
    sort(begin(t), end(t));
    triplets[i] = t;
    rep(j, 3) values.insert(triplets[i][j]);
  }
  int a = 0;
  map<ll, int> assoc;
  for (auto v : values)
    assoc[v] = a++;
  rep(i, n) {
    rep(j, 3) { triplets[i][j] = assoc[triplets[i][j]]; }
  }
  sort(begin(triplets), end(triplets),
       [](const vector<ll> &left, const vector<ll> &right) {
         if (left[0] == right[0])
           return right[1] < left[1];
         return left[0] < right[0];
       });

  Tree tree(a);
  for (auto &triple : triplets) {
    int d = tree.query(0, triple[1]);
    if (d < triple[2]) {
      cout << "Yes\n";
      return 0;
    }
    int v = tree.query(triple[1], triple[1]+1);
    tree.update(triple[1], min(v, (int)triple[2]));
  }
  cout << "No\n";
  return 0;
}
