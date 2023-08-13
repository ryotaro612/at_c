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
  int n;
  cin >> n;
  vector<int> left, right, consume(n + 1, 0);
  left.push_back(n);
  consume[n]++;
  right.push_back(n - 1);
  consume[n - 1]++;
  vector<int> *turn = &left;
  int i = n;
  while (i) {

    int j = i;
    while (turn->back() == j || consume[j] == j)
      j--;
    turn->push_back(j);
    consume[j]++;
    dbg(consume);
    dbg(i);
    while (i && consume[i] == i)
      i--;
    if (turn == &left)
      turn = &right;
    else
      turn = &left;
  }
  vector<int> res(left);
  reverse(begin(right), end(right));
  for (auto e : right)
    res.push_back(e);
  rep(j, size(res)) cout << res[j] << " \n"[j == (int)size(res) - 1];

  return 0;
}
