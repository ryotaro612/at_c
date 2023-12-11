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

string enc(vector<int> ptn) {
  string s;
  for (auto c : ptn)
    s.push_back(c);
  return s;
}

vector<pair<int, vector<int>>> calc_patterns(int num) {
  vector<int> ptn(num);
  rep(i, num) ptn[i] = i;
  map<string, pair<int, vector<int>>> mp;
  mp[enc(ptn)] = {0, ptn};
  queue<vector<int>> que;
  que.push(ptn);
  while (que.size()) {
    vector<int> cur = que.front();
    que.pop();
    rep(i, num - 1) {
      vector<int> new_ptn = cur;
      swap(new_ptn[i], new_ptn[i + 1]);
      if (!mp.contains(enc(new_ptn))) {
        mp[enc(new_ptn)] = {mp[enc(cur)].first + 1, new_ptn};
        que.push(new_ptn);
      }
    }
  }

  vector<pair<int, vector<int>>> res;
  for (auto [_, v] : mp) {
    res.push_back(v);
  }
  return res;
}
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<ll>> am(h, vector<ll>(w)), bm(h, vector<ll>(w));
  rep(r, h) { rep(c, w) cin >> am[r][c]; }
  rep(r, h) { rep(c, w) cin >> bm[r][c]; }
  auto h_ptns = calc_patterns(h);
  auto w_ptns = calc_patterns(w);
  for (auto [_, ptn] : h_ptns) {
    dbg(ptn);
  }
  int res = 100000;

  for (auto [h_cnt, h_ptn] : h_ptns) {
    for (auto [w_cnt, w_ptn] : w_ptns) {
      dbg(h_ptn);
      dbg(w_ptn);
      vector<vector<ll>> trans(h, vector<ll>(w));
      rep(r, h) {
        rep(c, w) { trans[r][c] = am[h_ptn[r]][w_ptn[c]]; }
      }
      rep(i, h) { dbg(trans[i]); }

      bool ok = true;
      rep(r, h) {
        rep(c, w) { ok = ok && trans[r][c] == bm[r][c]; }
      }
      if (ok)
        res = min(w_cnt + h_cnt, res);
    }
  }

  if (res >= 100000) {
    cout << -1 << endl;
  } else
    cout << res << endl;
  return 0;
}
