#include <bits/stdc++.h>
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
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> cv(n);
  vector<deque<char>> ques(m);
  rep(i, n) {
    cin >> cv[i];
    ques[--cv[i]].push_back(s[i]);
  }
  rep(i, m) {
    char c = ques[i].back();
    ques[i].pop_back();
    ques[i].push_front(c);
  }
  rep(i, n) {
    char c = ques[cv[i]].front();
    ques[cv[i]].pop_front();
    cout << c;
  }
  cout << endl;

  return 0;
}
