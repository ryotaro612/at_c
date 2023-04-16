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
ll mod = 998244353ll;
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

ll mypow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1) {
      res *= x;
      res %= mod;
    }
    n >>= 1;
    x *= x;
    x %= mod;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int q;
  cin >> q;
  deque<int> que;
  ll v = 1ll;
  que.push_back(v);
  rep(_, q) {
    int type;
    cin >> type;
    if (type == 1) {
      ll x;
      cin >> x;
      que.push_back(x);
      v *= 10ll;
      v %= mod;
      v += x;
      v %= mod;
    } else if (type == 2) {
      int d = que.size();
      int front = que.front();
      que.pop_front();
      v -= front * mypow(10ll, d - 1) % mod;
      if (v < 0)
        v += mod;
    } else {
      cout << v << endl;
    }
  }
  // while (que.size()) {
  //   cout << que.front();
  //   cout << " ";
  //   que.pop_front();
  // }
  // cout << endl;
  return 0;
}
#endif
