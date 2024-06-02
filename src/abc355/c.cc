#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}
int main() {
  int n, t;
  cin >> n >> t;
  vector<vector<bool>> grid(n, vector<bool>(n, true));
  vector<int> av(t);
  rep(i, t) cin >> av[i];
  vector<int> rows(n, 0), cols(n, 0);
  int diag = 0, anti_diag = 0;
  dbg("doge");
  rep(c, t) {
    // dbg(c);
    int j = av[c] % n;
	if(j == 0)
	  j = n;
    int i = (av[c] - j) / n + 1;
	// dbg(i, j, "before");
    i = (i + n - 1) % n;
    j = (j + n - 1) % n;
    //dbg(i, j);
    rows[i]++;
    cols[j]++;
    if (i == j)
      diag++;
    if (j == n - i - 1)
      anti_diag++;
	dbg(i, j);
    if (rows[i] == n || cols[j] == n || diag == n || anti_diag == n) {
      cout << c + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
