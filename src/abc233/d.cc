#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename K, typename V>
void debug_unorderedmap(unordered_map<K, V> mp) {
  for (pair<K, V> e : mp) {
    cout << "(" << e.first << " -> " << e.second << ") ";
  }
  cout << endl;
}

ll solve(int n, ll k, vector<ll> &av) {
  vector<ll> sum(n + 1, 0ll);
  sum[0] = 0ll;
  unordered_map<ll, ll> mp;
  rep(i, n) { sum[i + 1] = av[i] + sum[i]; }
  rep(i, n + 1) mp[sum[i]]++;

  // debug_unorderedmap(mp);
  ll res = 0ll;
  rep(i, n + 1) {
    mp[sum[i]]--;
    if (mp.find(k + sum[i]) != mp.end()) {
      assert(mp[k + sum[i]] >= 0);
      res += mp[k + sum[i]];
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; }
  cout << solve(n, k, a) << endl;
  return 0;
}
#endif
