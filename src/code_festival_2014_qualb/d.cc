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

class SegmentTree {
public:
  SegmentTree(int size, int invalid) {
    int n = 1;
    while (n < size)
      n *= 2;
    tree = vector<int>(n * 2 - 1, ninf = invalid);
  }
  /**
   * k番目の値(0-indexed)をaに変更する
   */
  void update(int i, int v) {
    i += offset();
    tree[i] = v;
    while (i > 0) {
      i = (i - 1) / 2;
      tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
  }

  int query(int left, int right) {
    return query(left, right, 0, 0, max_size());
  }

private:
  /**葉以外のノード数 */
  vector<int> tree;
  int ninf;

  int query(int q_l, int q_r, int root, int l, int r) {
    if (r <= q_l || q_r <= l)
      return ninf;
    if (q_l <= l && r <= q_r)
      return tree[root];
    else
      return max(query(q_l, q_r, root * 2 + 1, l, (l + r) / 2),
                 query(q_l, q_r, root * 2 + 2, (l + r) / 2, r));
  }
  int offset() { return max_size() - 1; }
  int max_size() { return (tree.size() + 1) / 2; }
};
vector<int> sub(vector<int> &hv) {
  int n = hv.size();
  SegmentTree tree(n, -1);
  rep(i, n) tree.update(i, hv[i]);
  rep(i, n) { dbg(i, tree.query(i, i + 1)); }
  vector<int> res(n);

  rep(i, n) {
    dbg(i);
    int lb = i + 1, ub = n + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      int mx = tree.query(i + 1, mid);
      dbg(mx, lb, mid, ub);
      if (mx <= hv[i]) {
        lb = mid;
      } else { // mv > hv[i];
        ub = mid;
      }
    }
    dbg(lb, lb - i - 1);
    res[i] = lb - i - 1;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> hv(n);
  rep(i, n) {
    int h;
    cin >> h;
    hv[i] = h;
  }
  vector<int> res = sub(hv);
  dbg(res);
  dbg("----");
  reverse(begin(hv), end(hv));
  vector<int> temp = sub(hv);
  rep(i, n) { cout << res[i] + temp[n - 1 - i] << endl; }

  return 0;
}
