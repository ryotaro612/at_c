#include <bits/stdc++.h>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #x << " = " << x   \
       << "\e[39m" << endl;
#else
#define dbg(x)
#endif
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type
operator<<(Ostream &os, const Cont &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}
struct Item {
  int rank, contest_i, a;

  Item(int r, int c, int aa) : rank(r), contest_i(c), a(aa) {}
};
struct Comp {
  bool operator()(Item const &item1, Item const &item2) {
    if (item1.rank != item2.rank)
      return item1.rank > item2.rank;
    else
      return item1.contest_i > item2.contest_i;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  set<int> used;
  priority_queue<Item, vector<Item>, Comp> que;
  rep(i, n) {
    rep(j, k) {
      int a;
      cin >> a;
      que.push({j, i, a});
    }
    vector<int> res;
    while (que.size() && (int)size(used) < k) {
      Item item = que.top();
      if (used.count(item.a)) {
        que.pop();
        continue;
      }
      // のこりのコンテスト数
      int rest_contest = n - 1 - i;
      // 残りの試合でkに入りそうな数の最大
      int cand = rest_contest * (item.rank);

      if (cand + (int)size(used) < k) {
        que.pop();
        used.insert(item.a);
        res.push_back(item.a);
      } else
        break;
    }
    sort(begin(res), end(res));
    if(res.size())
      rep(j, size(res)) { cout << res[j] << " \n"[j == (int)size(res) - 1]; }
    else
      cout << endl;
  }
  return 0;
}
