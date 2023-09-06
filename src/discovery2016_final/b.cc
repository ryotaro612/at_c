#include <algorithm>
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

class Bit {
public:
  /**
   * [0,n)
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
  int total() { return sum(bit.size() - 1); }

private:
  vector<int> bit;
};

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<int> tv(n);
  vector<ll> av(n);
  rep(i, n) cin >> tv[i];
  rep(i, n) cin >> av[i];
  vector<int> order(n);
  rep(i, n) order[i] = i;

  sort(begin(order), end(order), [&](const int &a, const int &b) {
    if (av[a] != av[b])
      return av[b] < av[a];
    return tv[a] < tv[b];
  });
  int inf = *max_element(begin(tv), end(tv)) + 1;
  int lb = -1, ub = inf;

  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    vector<int> times(mid + 1);
    rep(i, mid + 1) times[i] = i;
    set<int> cands(begin(times), end(times));
    ll oishihsa = 0;
    for (int i : order) {
      if (cands.size() == 0)
        break;
      else if (tv[i] <= *begin(cands))
        continue;
      else {
        cands.erase(prev(cands.lower_bound(tv[i])));
        oishihsa += av[i];
        if (x <= oishihsa)
          break;
      }
    }
    if (oishihsa < x)
      lb = mid;
    else
      ub = mid;
  }
  if(ub == inf)
    cout << -1;
  else
    cout << ub + 1;
  cout << endl;

  return 0;
}
