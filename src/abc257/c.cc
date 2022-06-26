#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<ll> wv(n);
  rep(i, n) cin >> wv[i];
  map<ll, int> adult_num, child_num;
  rep(i, n) {
    if (adult_num.find(wv[i]) == adult_num.end())
      adult_num[wv[i]] = 0;
    if (child_num.find(wv[i]) == child_num.end())
      child_num[wv[i]] = 0;

    if (s[i] == '1') {
      adult_num[wv[i]] += 1;
    } else {
      child_num[wv[i]] += 1;
    }
  }
  int n_weights = adult_num.size();
  vector<ll> weights(n_weights);
  int i = 0;
  for (auto [w, _] : adult_num) {
    weights[i++] = w;
  }
  vector<int> child_prefix(child_num.size(), 0),
      adult_suffix(adult_num.size(), 0);
  rep(i, n_weights) {
    if (i > 0) {
      child_prefix[i] = child_prefix[i - 1] + child_num[weights[i - 1]];
    }
  }
  for (int i = n_weights - 1; i >= 0; i--) {
    if (i == n_weights - 1) {
      adult_suffix[i] = adult_num[weights[i]];
    } else {
      adult_suffix[i] = adult_num[weights[i]] + adult_suffix[i + 1];
    }
  }
  // rep(i, n_weights) {
  //   cout << weights[i] << " child " << child_prefix[i] << " adult "
  //        << adult_suffix[i] << endl;
  // }
  int res = 0;
  rep(i, n_weights) { res = max(res, child_prefix[i] + adult_suffix[i]); }
  int count = 0;
  rep(i, n) {
    if (s[i] == '0')
      count++;
  }
  res = max(res, count);
  res = max(res, n - count);
  cout << res << endl;

  return 0;
}
#endif
