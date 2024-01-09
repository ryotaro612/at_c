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
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) {
    cin >> sv[i];
    reverse(begin(sv[i]), end(sv[i]));
  }
  vector<vector<int>> trie(1000010, vector<int>(26, 0));
  int cur = 1;
  vector<vector<int>> paths(n);
  vector<bool> is_end(1000010, false);
  rep(i, n) {
    int node = 0;
    rep(j, sv[i].size()) {
      paths[i].push_back(node);
      if (trie[node][sv[i][j] - 'a'] == 0) {
        trie[node][sv[i][j] - 'a'] = cur++;
      }
      node = trie[node][sv[i][j] - 'a'];
    }
    is_end[node] = true;
  }
  ll res = 0;
  rep(i, n) {
    string s = sv[i];
    set<char> suffix;
    for (int j = sv[i].size() - 1; j >= 0; j--) {
      suffix.insert(sv[i][j]);
      int node = paths[i][j];
      for (char c : suffix) {
        res += is_end[trie[node][c - 'a']];
      }
    }
  }
  cout << res - n << endl;

  return 0;
}
