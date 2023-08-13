#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #x << " = " << x   \
       << "\e[39m" << endl;
#else
#define dbg(x)
#endif
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type
operator<<(Ostream &os, const Cont &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}
int main() {
  int n, q;
  string s;

  cin >> n >> s >> q;
  vector<int> mod(n, -1);

  int all_i = -1;
  int lower = false;
  rep(i, q) {
    int t, x;
    char c;
    cin >> t >> x >> c;
    if (t == 1) {
      s[--x] = c;
      mod[x] = i;
    } else if (t == 2) {
      all_i = i;
      lower = true;
    } else {
      all_i = i;
      lower = false;
    }
  }
  rep(i, n) {
    char c;
    if (all_i <= mod[i])
      c= s[i];
    else if (lower)
      c = tolower(s[i]);
    else
      c = toupper(s[i]);
    cout << c;
  }
  cout << endl;
  return 0;
}
