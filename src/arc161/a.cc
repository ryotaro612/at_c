#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  map<ll, int> freq;
  rep(i, n) {

    cin >> av[i];
    freq[av[i]]++;
    // cout << freq[av[i]] << endl;
  }
  int mx_freq = 0;
  rep(i, n) { mx_freq = max(mx_freq, freq[av[i]]); }

  if (mx_freq < n / 2 + 1) {
    cout << "Yes\n";
    return 0;
  } else if (mx_freq > n / 2 + 1) {
    cout << "No\n";
    return 0;
  }
  ll c;
  for (auto [a, b] : freq) {
    if (b == mx_freq)
      c = a;
  }
  sort(av.begin(), av.end());

  if (av[0] == c) {
    cout << "Yes\n";
  } else
    cout << "No\n";

  return 0;
}
#endif
