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

bool smoke(vector<int> av, vector<int> bv) {
  sort(begin(av), end(av));
  sort(begin(bv), end(bv));
  rep(i, av.size()) {
    if (av[i] != bv[i])
      return false;
  }
  return true;
}
class Bit {
public:
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

int main() {
  int n;
  cin >> n;
  vector<int> av(n), bv(n);
  map<int, int> pos_a, pos_b;
  rep(i, n) {
    cin >> av[i];
    pos_a[av[i]] = i;
  }
  rep(i, n) {
    cin >> bv[i];
    pos_b[bv[i]] = i;
  }
  if (!smoke(av, bv)) {
    cout << "No\n";
    return 0;
  }
  set<int> freq(begin(av), end(av));
  if ((int)freq.size() < n) {
    cout << "Yes\n";
    return 0;
  }

  Bit ba(n + 1);
  ll inv_a = 0;
  rep(i, n) {
    inv_a += ba.sum_range(av[i], n + 1);
    ba.add(av[i], 1);
  }
  Bit bb(n + 1);
  ll inv_b = 0;
  rep(i, n) {
    inv_b += bb.sum_range(bv[i], n + 1);
    bb.add(bv[i], 1);
  }
  if((inv_a + inv_b) % 2) {
    cout <<"No\n";
  }else
    cout << "Yes\n";
  
  

  return 0;
}
