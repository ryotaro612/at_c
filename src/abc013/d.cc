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
  int n, m;
  ll d;
  cin >> n >> m >> d;
  vector<int> amida(n);
  rep(i, n) amida[i] = i;
  rep(i, m) {
    int a;
    cin >> a;
    swap(amida[a - 1], amida[a]);
  }
  vector<int> after(n);
  rep(i, n) { after[amida[i]] = i; }
  dbg(after);
  vector<vector<int>> loops;
  vector<pair<int, int>> pointers(n, {-1, -1});
  rep(i, n) {
    if (pointers[i].first != -1)
      continue;
    loops.push_back(vector<int>());
    int cur = i;
    while (pointers[cur].first == -1) {
      loops.back().push_back(cur);
      pointers[cur] = {loops.size() - 1, loops.back().size() - 1};
      cur = after[cur];
    }
  }
  dbg(loops);
  rep(i, n) {
    auto [a, b] = pointers[i];
    dbg(a, b);
    cout << loops[a][((ll)b +d) % loops[a].size()] + 1<< endl;
    
  }
  return 0;
}
