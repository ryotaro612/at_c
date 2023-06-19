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

int count(vector<ll> &av) {
  set<ll> st(av.begin(), av.end());
  int n = av.size(), i = 0;
  map<ll, int> mp;
  for (ll e : st)
    mp[e] = i++;
  rep(i, n) { av[i] = mp[av[i]]; }
  Bit bit(n);
  int res = 0;
  rep(i, n) {
    res += av[i] - bit.sum(av[i]);
    bit.add(av[i], 1);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  set<ll> st;
  rep(i, n) {
    cin >> av[i];
    st.insert(av[i]);
  }
  int i = 0;
  map<ll, int> mp;
  for (auto e : st) {
    mp[e] = i++;
  }
  rep(i, n) { av[i] = mp[av[i]]; }
  int res = 0;
  debug(av);
  rep(i, n) {
    if (i % 2 != av[i] % 2) {
      res++;
    }
  }
  cout << res / 2 << endl;

  return 0;
}
#endif
