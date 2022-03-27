#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class Bit {
public:
  Bit(int max_v) : bit(max_v + 1, 0) {}

  int sum(int i) {
    int res = 0;
    while (0 < i) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }

  void add(int value, int i) {
    int max_v = static_cast<int>(bit.size()) - 1;
    while (i <= max_v) {
      bit[i] += value;
      i += i & -i;
    }
  }

private:
  vector<int> bit;
};

void compress(vector<ll> &bv, vector<ll> &dv) {
  vector<ll> v;
  for (auto e : bv)
    v.push_back(e);
  for (auto e : dv)
    v.push_back(e);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int c = 1;
  unordered_map<ll, int> mp;
  for (auto e : v)
    mp[e] = c++;

  rep(i, bv.size()) { bv[i] = mp[bv[i]]; }
  rep(i, dv.size()) { dv[i] = mp[dv[i]]; }
}

string solve2(int n, int m, vector<ll> &av, vector<ll> &bv, vector<ll> &cv,
              vector<ll> &dv) {
  compress(bv, dv);
  vector<pair<ll, ll>> choco(n), box(m);
  rep(i, n) choco[i] = {av[i], bv[i]};
  rep(i, m) box[i] = {cv[i], dv[i]};

  sort(choco.begin(), choco.end());
  sort(box.begin(), box.end());

  // for (auto c : choco) {
  //   cout << "(" << c.first << ", " << c.second << ") ";
  // }
  // cout << endl;
  // cout << " ---- " << endl;
  // for (auto c : box) {
  //   cout << "(" << c.first << ", " << c.second << ") ";
  // }
  // cout << endl;
  // cout << " ---- " << endl;
  const int horizon_max = 200000;
  Bit bit_choco(horizon_max), bit_box(horizon_max);

  int pointer = m - 1;
  bool done = false;
  for (int i = n - 1; 0 <= i; i--) {
    bit_choco.add(1, choco[i].second);
    while (!done && choco[i].first <= box[pointer].first) {
      bit_box.add(1, box[pointer].second);
      if (pointer == 0) {
        done = true;
        break;
      } else
        pointer--;
    }
    if (bit_box.sum(horizon_max) - bit_box.sum(choco[i].second - 1) <
        bit_choco.sum(horizon_max) - bit_choco.sum(choco[i].second - 1)) {
      return "No";
    }
  }

  return "Yes";
}

string solve(int n, int m, vector<ll> &av, vector<ll> &bv, vector<ll> &cv,
             vector<ll> &dv) {
  vector<pair<ll, ll>> choco(n), box(m);
  rep(i, n) choco[i] = {av[i], bv[i]};
  rep(i, m) box[i] = {cv[i], dv[i]};

  sort(choco.begin(), choco.end());
  sort(box.begin(), box.end());

  int pointer = m - 1;
  multiset<ll> horizon;
  bool consumed = false;
  for (int i = n - 1; 0 <= i; i--) {
    while (!consumed && choco[i].first <= box[pointer].first) {
      horizon.insert(box[pointer].second);
      if (pointer == 0) {
        consumed = true;
        break;
      } else {
        pointer--;
      }
    }
    auto found = horizon.lower_bound(choco[i].second);
    if (found == horizon.end())
      return "No";
    else {
      horizon.erase(found);
    }
  }

  return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(n), bv(n), cv(m), dv(m);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  rep(i, m) cin >> cv[i];
  rep(i, m) cin >> dv[i];
  cout << solve(n, m, av, bv, cv, dv) << endl;
  return 0;
}
#endif
