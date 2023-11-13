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

ll solve_small(ll n, vector<string> &sv) {
  vector<string> cands;
  ll res = 0;
  rep(i, 1 << n) {
    string cand;
    rep(j, n) {
      if (i & (1 << j))
        cand.push_back('a');
      else
        cand.push_back('b');
    }
    bool ok = true;
    for (string &s : sv)
      ok = ok && cand.find(s) == string::npos;
    if (ok)
      res++;
  }
  return res;
}

set<int> encode(vector<string> &sv) {
  set<int> res;
  rep(i, 1 << 6) {
    string cand;
    rep(j, 6) {
      if (i & (1 << j))
        cand.push_back('a');
      else
        cand.push_back('b');
    }
    bool ok = true;
    for (auto &s : sv)
      ok = ok && cand.find(s) == string::npos;
    if (ok)
      res.insert(i);
  }
  return res;
}
const ll MOD = 998244353ll;

vector<vector<ll>> sqmat_pow2(vector<vector<ll>> &mat) {
  vector<vector<ll>> res(mat.size(), vector<ll>(mat.size(), 0));
  rep(r, mat.size()) {
    rep(c, mat.size()) {
      rep(i, mat.size()) {
        res[r][c] += mat[r][i] * mat[i][c] % MOD;
        res[r][c] %= MOD;
      }
    }
  }
  return res;
}

ll solve_large(ll n, vector<ll> &dp, vector<vector<ll>> &mat) {
  if (n == 0) {
    ll res = 0;
    for (auto e : dp) {
      res += e;
      res %= MOD;
    }
    return res;
  }
  ll dec = 1ll;
  vector<vector<ll>> forward = mat;
  while (n - dec * 2ll >= 0ll) {
    forward = sqmat_pow2(forward);
    dec *= 2ll;
  }
  vector<ll> next_dp(1 << 6, 0);
  rep(i, 1 << 6) {
    rep(j, 1 << 6) {
      next_dp[i] += forward[i][j] * dp[j] % MOD;
      next_dp[i] %= MOD;
    }
  }
  dp = next_dp;

  return solve_large(n - dec, dp, mat);
}

vector<vector<ll>> build_mat(vector<string> &sv) {
  map<string, int> mp;
  map<int, string> rev;

  rep(i, 1 << 6) {
    string s;
    rep(j, 6) {
      if (i & (1 << j))
        s.push_back('a');
      else
        s.push_back('b');
    }
    mp[s] = i;
    rev[i] = s;
  }
  vector<vector<ll>> res(1 << 6, vector<ll>(1 << 6, 0));
  rep(i, 1 << 6) {
    string s = rev[i];
    string next1 = string(begin(s) + 1, end(s)) + "a";
    string next2 = string(begin(s) + 1, end(s)) + "b";
    for (auto next : {next1, next2}) {
      bool ok = true;
      for (auto ng : sv) {
        ok = ok && next.find(ng) == string::npos;
      }
      if (ok) {
        int row = mp[next];
        int col = i;
        res[row][col] = 1;
      }
    }
  }
  return res;
}

int main() {
  ll n;
  int m;
  cin >> n >> m;
  vector<string> sv(m);
  rep(i, m) cin >> sv[i];
  ll res;
  if (n < 6) {
    res = solve_small(n, sv);
  } else {
    vector<ll> dp(1 << 6, 0);
    rep(i, 1 << 6) {
      string s;
      rep(j, 6) {
        if (i & (1 << j))
          s.push_back('a');
        else
          s.push_back('b');
      }
      bool ok = true;
      for (auto ng : sv)
        ok = ok && s.find(ng) == string::npos;
      if (ok)
        dp[i] = 1;
    }
    dbg(dp);
    vector<vector<ll>> mat = build_mat(sv);

    // dbg(mat);
    res = solve_large(n - 6ll, dp, mat);
  }
  cout << res << endl;
  return 0;
}
