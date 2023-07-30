#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
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
// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> free, opener, req;
  rep(i, n) {
    ll t, x;
    cin >> t >> x;
    if (t == 0)
      free.push_back(x);
    else if (t == 1)
      req.push_back(x);
    else
      opener.push_back(x);
  }
  sort(begin(opener), end(opener), greater<ll>());
  sort(begin(free), end(free), greater<ll>());
  sort(begin(req), end(req), greater<ll>());
  ll satis = 0ll;
  multiset<pair<ll, int>> que;
  const int FREE = 1, REQ = 0;
  while ((int)size(que) < min(m, (int)size(free))) {
    satis += free[size(que)];
    que.insert({free[size(que)], FREE});
  }
  ll res = satis;
  int openable = 0, n_req = 0;
  for (int n_opener = 1; n_opener <= min(m, (int)size(opener)); n_opener++) {
    while ((int)size(que) > m - n_opener) {
      auto can = begin(que);
      if (can->second == REQ)
        openable++;
      satis -= can->first;
      que.erase(can);
    }
    openable += opener[n_opener - 1];
    while ((int)size(que) < m - n_opener && openable &&
           n_req < (int)size(req)) {
      openable--;
      satis += req[n_req];
      que.insert({req[n_req++], REQ});
    }
    while (openable && size(que) && n_req < (int)size(req) &&
           begin(que)->second == FREE && begin(que)->first < req[n_req]) {
      auto can = begin(que);
      satis -= can->first;
      que.erase(can);
      openable--;
      satis += req[n_req];
      que.insert({req[n_req++], REQ});
    }
    res = max(res, satis);
  }
  cout << res << endl;
  return 0;
}
