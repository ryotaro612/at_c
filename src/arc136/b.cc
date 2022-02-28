#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class BinaryIndexTree final {
public:
  vector<int> bit;
  BinaryIndexTree(int max_value) : bit(max_value + 1){};

  int sum(int i) {
    int res = 0;
    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }
  void add(int i, int v) {
    int max_value = get_max_value();
    while (i <= max_value) {
      bit[i] += v;
      i += i & -i;
    }
  }
  int get_max_value() { return bit.size() - 1; }
};

int count_inversion_number(vector<int> &v, int max_value) {
  BinaryIndexTree bit(max_value);

  int n = v.size();
  int res = 0;
  for (ll i = 0ll; i < n; i++) {
    res += i - bit.sum(v[i]);
    bit.add(v[i], 1);
  }
  return res;
}

string solve(int n, vector<int> &av, vector<int> &bv) {

  vector<int> ac(av.begin(), av.end());
  vector<int> bc(bv.begin(), bv.end());
  sort(ac.begin(), ac.end());
  sort(bc.begin(), bc.end());

  rep(i, n) {
    if (ac[i] != bc[i]) {
      return "No";
    }
  }
  rep(i, n) {
    if (0 < i) {
      if (ac[i - 1] == ac[i])
        return "Yes";
    }
  }

  if (count_inversion_number(av, 5000) % 2 ==
      count_inversion_number(bv, 5000) % 2) {
    return "Yes";
  } else
    return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  cout << solve(n, av, bv) << endl;

  return 0;
}
#endif
