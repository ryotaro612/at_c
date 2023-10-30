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

unordered_map<ll, int> enumerate(vector<ll> &sub) {
  unordered_map<ll, int> res;
  rep(i, 1 << (int)sub.size()) {
    ll pos = 0;
    rep(j, sub.size()) {
      if (i & (1 << j))
        pos += sub[j];
      else
        pos -= sub[j];
    }
    res[pos] = i;
  }
  return res;
}

vector<vector<bool>> compute_cands(int start, vector<ll> &av, ll goal) {
  vector<ll> sub;
  for (int i = start; i < (int)av.size(); i += 2)
    sub.push_back(av[i]);

  vector<ll> first = vector(begin(sub), begin(sub) + sub.size() / 2);
  unordered_map<ll, int> first_map = enumerate(first);
  vector<ll> second = vector(begin(sub) + sub.size() / 2, end(sub));
  unordered_map<ll, int> second_map = enumerate(second);
  dbg(first, second);
  for (auto &[v, mask] : first_map) {
    if (second_map.contains(goal - v)) {
      vector<bool> res;
      rep(i, first.size()) {
        if (mask & (1 << i))
          res.push_back(true);
        else
          res.push_back(false);
      }
      rep(i, second.size()) {
        if (second_map[goal - v] & (1 << i))
          res.push_back(true);
        else
          res.push_back(false);
      }
      dbg(mask, second_map[goal - v]);

      return {res};
    }
  }
  return {};
}

int main() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<vector<bool>> y_cands = compute_cands(0, av, y),
                       x_cands = compute_cands(1, av, x);
  for (auto &y_cand : y_cands) {
    for (auto &x_cand : x_cands) {
      int d = 1;
      int y_i = 0, x_i = 0;
      string res;
      while (y_i < (int)y_cand.size() || x_i < (int)x_cand.size()) {
        if (y_i < (int)y_cand.size()) {
          if (y_cand[y_i] > 0) {
            if (d == 1)
              res.push_back('L');
            else // d == 3
              res.push_back('R');
            d = 0;
          } else { // y_cand[y_i] < 0
            if (d == 1)
              res.push_back('R');
            else
              res.push_back('L');
            d = 2;
          }
          y_i++;
        }
        if (x_i < (int)x_cand.size()) {
          if (x_cand[x_i] > 0) {
            if (d == 0)
              res.push_back('R');
            else
              res.push_back('L');
            d = 1;
          } else {
            if (d == 0)
              res.push_back('L');
            else
              res.push_back('R');
            d = 3;
          }
          x_i++;
        }
      }
      cout << "Yes\n" << res << "\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
