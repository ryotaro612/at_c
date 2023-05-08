
#include <algorithm>
#include <chrono>
#include <complex>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define REP(i, m, n) for (int i = int(m); i < int(n); i++)
#define RREP(i, m, n) for (int i = int(n) - 1; i >= int(m); --i)
#define EACH(i, c) for (auto &(i) : c)
#define all(c) begin(c), end(c)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(begin(c), end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
// #define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x) cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s)                                                               \
  do {                                                                         \
  } while (0)
#define dump(x)                                                                \
  do {                                                                         \
  } while (0)
#define BR
#endif
using namespace std;

#include <atcoder/all>

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int, int>;
using VP = vector<PII>;
template <class T> using V = vector<T>;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

bool solve(LL m, LL r) {
  LL a = 1;
  while (a <= m)
    a *= 10;
  if (m + a <= r)
    return false;
  if (m * 10 <= r)
    return false;
  return true;
}

long long meguru_bin(LL l, LL r) {
  long long ok = r;
  long long ng = l - 1;

  while (abs(ok - ng) > 1) {
    long long mid = ng + (ok - ng) / 2;
    if (solve(mid, r))
      ok = mid;
    else
      ng = mid;
  }

  return ok;
}

void solve() {
  LL l, r;
  cin >> l >> r;

  l = meguru_bin(l, r);
  // dump(l);

  cout << r - l + 1 << endl;
}

signed main() {
  int t;
  cin >> t;
  REP(i, 0, t)
  solve();

  return 0;
}
#include <algorithm>
#include <chrono>
#include <complex>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define REP(i, m, n) for (int i = int(m); i < int(n); i++)
#define RREP(i, m, n) for (int i = int(n) - 1; i >= int(m); --i)
#define EACH(i, c) for (auto &(i) : c)
#define all(c) begin(c), end(c)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(begin(c), end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
// #define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x) cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s)                                                               \
  do {                                                                         \
  } while (0)
#define dump(x)                                                                \
  do {                                                                         \
  } while (0)
#define BR
#endif
using namespace std;

#include <atcoder/all>

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int, int>;
using VP = vector<PII>;
template <class T> using V = vector<T>;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

bool solve(LL m, LL r) {
  LL a = 1;
  while (a <= m)
    a *= 10;
  if (m + a <= r)
    return false;
  if (m * 10 <= r)
    return false;
  return true;
}

long long meguru_bin(LL l, LL r) {
  long long ok = r;
  long long ng = l - 1;

  while (abs(ok - ng) > 1) {
    long long mid = ng + (ok - ng) / 2;
    if (solve(mid, r))
      ok = mid;
    else
      ng = mid;
  }

  return ok;
}

void solve() {
  LL l, r;
  cin >> l >> r;

  l = meguru_bin(l, r);
  // dump(l);

  cout << r - l + 1 << endl;
}

signed main() {
  int t;
  cin >> t;
  REP(i, 0, t)
  solve();

  return 0;
}
// #endif
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <string>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

vector<ll> gen_cand(ll mid) {
  vector<ll> res;
  res.push_back(mid * 10ll);
  string s = to_string(mid);
  if (s.size() == 1)
    return res;
  ll cand = stoll(string(s.begin() + 1, s.end()));
  if (cand)
    res.push_back(cand);
  cand = stoll(string(s.begin(), s.end() - 1));
  if (cand)
    res.push_back(cand);
  return res;
}

// #ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    cout << "t -> " << t << endl;
    ll l, r;
    cin >> l >> r;
    ll lb = l - 1ll, ub = r + 1ll;
    while (ub - lb > 1) {
      ll mid = (ub + lb) / 2ll;
      vector<ll> cands = gen_cand(mid);
      bool ok = true;
      cout << "mid: " << mid << endl;
      for (auto c : cands) {
        cout << c << " ";
        if (l <= c && c <= r)
          ok = false;
      }
      cout << endl;
      if (!ok)
        ub = mid;
      else
        lb = mid;
    }
    cout << lb - l + 1ll << endl;
  }
  return 0;
}
// #endif
