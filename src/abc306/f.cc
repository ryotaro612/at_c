#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  os << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}
void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

class Bit {
public:
  /**
   * [1,n)にある値をあつかえる。
   */
  Bit(int n) : bit(vector<int>(n + 1, 0)) {}
  /**
   *  sum of arr[0,to)
   */
  int sum(int to) {
    int res = 0;
    while (to) {
      res += bit[to];
      to -= to & -to;
    }
    return res;
  }
  /**
   * sum of arr[from,to)
   */
  int sum_range(int from, int to) { return sum(to) - sum(from); }

  void add(int pos, int v) {
    pos++;
    while (pos < static_cast<int>(bit.size())) {
      bit[pos] += v;
      pos += pos & -pos;
    }
  }

private:
  vector<int> bit;
};
#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> am(n, vector<ll>(m));
  set<ll> a_set;
  rep(i, n) {
    rep(j, m) {
      cin >> am[i][j];
      a_set.insert(am[i][j]);
    }
  }
  map<ll, int> remap;
  int d = 0;
  for (auto e : a_set) {
    remap[e] = d++;
  }
  rep(i, n) {
    sort(am[i].begin(), am[i].end());
    rep(j, m) { am[i][j] = remap[am[i][j]]; }
    debug(am[i]);
  }
  Bit bit(n * m);
  ll res = 0;
  for (int i = n - 1; i >= 0; i--) {
    rep(j, m) {
      ll others = bit.sum(am[i][j]) - j;
      res += others + (j + 1) * (n - 1 - i);
      bit.add(am[i][j], 1);
      debug(i, j, res, others);
    }
  }
  cout << res << endl;
  return 0;
}

#endif
