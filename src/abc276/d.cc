#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

void put(ll v, unordered_set<ll> &d) {
  if (d.find(v) != d.end())
    return;
  d.insert(v);
  if (v == 1) {
    return;
  }
  if (v % 2 == 0) {
    put(v / 2ll, d);
  }
  if (v % 3 == 0) {
    put(v / 3ll, d);
  }
}

ll count(ll a, ll e, unordered_map<ll, ll> &cache) {
  if (cache.find(a) != cache.end()) {
    return cache[a];
  }
  if (a == e)
    return cache[a] = 0;
  ll result = -1ll;
  if (a % 2 == 0) {
    ll temp = count(a / 2ll, e, cache);
    if (temp != -1) {
      result = 1ll + temp;
    }
  }
  if (a % 3 == 0) {
    ll temp = count(a / 3ll, e, cache);
    if (temp != -1) {
      if (result == -1)
        result = 1ll + temp;
      else
        result = min(result, 1ll + temp);
    }
  }
  return cache[a] = result;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  unordered_set<ll> d;
  rep(i, n) { put(av[i], d); }

  ll result = numeric_limits<ll>::max();
  for (auto e : d) {
    // cout << e << "----" << endl;
    ll temp = 0ll;
    bool ok = true;
    unordered_map<ll, ll> cache;
    rep(i, n) {
      ll a = av[i];
      ll cnt = count(a, e, cache);
      // cout << a << " " << cnt << endl;
      if (cnt == -1)
        ok = false;
      else
        temp += cnt;
    }
    if (ok) {
      result = min(temp, result);
    }
  }
  if (result == numeric_limits<ll>::max()) {
    cout << -1;
  } else
    cout << result;
  cout << endl;

  return 0;
}
#endif
