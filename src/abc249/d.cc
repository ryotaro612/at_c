#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<ll> compute_divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end()); // 昇順に並べる
  return ret;
}

ll solve(int n, vector<ll> &av) {
  unordered_map<ll, ll> freq;

  for (auto a : av) {
    freq[a]++;
  }
  unordered_map<ll, ll> freq2(freq);

  ll res = 0ll;

  for (const auto [a, count] : freq) {
    vector<ll> divs = compute_divisor(a);
    for (auto d1 : divs) {
      ll d2 = a / d1;
      res += count * freq2[d1] * freq2[d2];
    }
  }
  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  cout << solve(n, av) << endl;
  return 0;
}
//#endif
