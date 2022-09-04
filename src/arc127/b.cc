#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow3(int n) {
  ll res = 1ll;
  while (n-- > 0ll)
    res *= 3ll;
  return res;
}

string tri(ll n, int l) {
  string s;
  for (int i = l - 1; i >= 0; i--) {
    ll base = pow3(i);
    if (n >= 2ll * base) {
      n -= 2ll * base;
      s.push_back('2');
    } else if (n >= base) {
      n -= base;
      s.push_back('1');
    } else
      s.push_back('0');
  }
  assert(n == 0ll);
  return s;
}

vector<string> solve(ll n, ll l) {
  vector<string> sv;
  for (ll i = 0ll; i < n; i++) {
    sv.push_back(tri(2ll * pow3(l - 1ll) + i, l));
  }
  // cout << "doge" << sv.size() << endl;
  //  for (auto s : sv)
  //    cout << s << endl;
  //  cout << "---" << endl;
  vector<string> res(sv.begin(), sv.end());
  for (string s : sv) {
    map<char, char> mp;
    mp['0'] = '1';
    mp['1'] = '2';
    mp['2'] = '0';
    string new_s;
    for (auto c : s)
      new_s.push_back(mp[c]);
    res.push_back(new_s);
    mp['0'] = '2';
    mp['1'] = '0';
    mp['2'] = '1';
    new_s = "";
    for (auto c : s)
      new_s.push_back(mp[c]);
    res.push_back(new_s);
  }
  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n, l;
  cin >> n >> l;
  vector<string> res = solve(n, l);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
//#endif
