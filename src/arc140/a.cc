#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

template <typename T> vector<T> get_divisors(T n) {
  vector<T> res;
  for (T i = 1ll; i * i <= n; i++) {
    if (n % i == 0ll) {
      res.push_back(i);
      if (i != n / i)
        res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int solve(int n, int k, string s) {
  vector<int> divisors = get_divisors(n);
  for (int divisor : divisors) {
    int count = 0;
    rep(i, divisor) {
      unordered_map<char, int> chars;
      for (int j = 0; i + j < n; j += divisor) {
        chars[s[i + j]]++;
      }
      int most_freq = 0;
      for (auto [_, num] : chars)
        most_freq = max(most_freq, num);
      // cout << "divisor " << divisor << "i: " << most_freq << endl;
      count += n / divisor - most_freq;
    }
    if (count <= k) {
      return divisor;
    }
  }
  assert(false);
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  cout << solve(n, k, s) << endl;
  return 0;
}
#endif
