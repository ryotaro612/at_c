#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/**
t = 0 k = 1
 */
char sub(string &s, ll t, ll k) {
  vector<ll> index = {k - 1};
  // cout << "doge" << endl;
  for (ll i = 0ll; i < t; i++) {
    if (index.back() == 0)
      break;
    index.push_back(index.back() / 2ll);
  }
  reverse(index.begin(), index.end());
  // cout << "foobar" << endl;
  int offset = (t + 1ll - (ll)index.size()) % 3ll;
  // rep(i, index.size()) cout << index[i] << endl;
  char res = ((s[index[0]] - 'A') + offset) % 3 + 'A';
  // cout << "2foobar" << endl;
  for (int i = 1; i < (int)index.size(); i++) {
    if (index[i - 1] * 2ll == index[i]) {
      res += 1;
    } else {
      res += 2;
    }
    if ('C' < res)
      res -= 3;
  }
  return res;
}

vector<char> solve(string &s, int q, vector<ll> &tv, vector<ll> &kv) {
  vector<char> res(q);
  rep(i, q) { res[i] = sub(s, tv[i], kv[i]); }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<ll> tv(q), kv(q);
  rep(i, q) { cin >> tv[i] >> kv[i]; }
  vector<char> res = solve(s, q, tv, kv);
  for (char e : res)
    cout << e << endl;
  return 0;
}
#endif
