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

bool achievable(vector<ll> &av, vector<ll> &bv) {
  int n = av.size();
  multiset<ll> a_set, b_set;
  for (ll i = 0ll; i < n; i++) {
    a_set.insert(av[i] + i);
    b_set.insert(bv[i] + i);
  }
  return a_set == b_set;
}

class Bit {
public:
  Bit(int n) {
    bit.resize(n + 1);
    fill(bit.begin(), bit.end(), 0);
  }
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
  int n;
  cin >> n;
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  if (!achievable(av, bv)) {
    cout << -1 << endl;
    return 0;
  }
  map<ll, set<int>> pos_map;
  for (ll i = 0; i < n; i++)
    pos_map[av[i] + i].insert(i);

  vector<int> a_order(n);
  for (ll i = 0; i < n; i++) {
    a_order[*pos_map[bv[i] + i].begin()] = i;
    pos_map[bv[i] + i].erase(pos_map[bv[i] + i].begin());
  }
  // rep(i, n) cout << a_order[i] << " ";
  // cout << endl;
  ll res = 0;
  Bit bit(n);
  rep(i, n) {
    res += i - bit.sum(a_order[i]);
    bit.add(a_order[i], 1);
  }
  cout << res << endl;

  return 0;
}
#endif
