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

ll calc_damege(ll base, ll combo) {
  return base + base / 10ll * (combo / 10ll);
}
// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  string s;
  cin >> s;
  ll res = 0ll, combo = 0ll, kabu = 5;
  vector<ll> delta_kabu((ll)size(s) + 30ll, 0ll),
      delta_combo((ll)size(s) + 30ll, 0ll);
  for (int i = 0; i < (int)size(s);) {
    kabu += delta_kabu[i];
    combo += delta_combo[i];
    if (s[i] == 'N') {
      if (kabu) {
        res += calc_damege(10ll, combo);
        kabu--;
        delta_combo[i + 2]++;
        delta_kabu[i + 7]++;
      }
      i++;
    } else if (s[i] == 'C') {
      if (kabu >= 3) {
        res += calc_damege(50ll, combo);
        kabu -= 3;
        delta_combo[i + 4]++;
        delta_kabu[i + 9] += 3;
        combo += delta_combo[i + 1] + delta_combo[i + 2];
        kabu += delta_kabu[i + 1] + delta_kabu[i + 2];
        i += 3;
      } else
        i++;
    } else
      i++;
  }
  debug(combo);
  debug(delta_kabu);
  debug(delta_combo);
  cout << res << endl;
  return 0;
}
