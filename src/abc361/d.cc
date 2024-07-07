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
const ll inf = 1ll << 60ll;

void solve(string &s, map<string, ll> &cache) {
  int n = s.size();
  vector<int> vacant, fill;
  rep(i, n) {
    if (s[i] == ' ')
      vacant.push_back(i);
    else
      fill.push_back(i);
  }
  // dbg("!", s, "!");
  rep(i, fill.size() - 1) {
    if (fill[i] + 1 != fill[i + 1])
      continue;
    int j = i + 1;
    string t(s.size(), ' ');
    rep(k, fill.size()) {
      if (k == i)
        t[vacant[0]] = s[fill[i]];
      else if (k == j)
        t[vacant[1]] = s[fill[j]];
      else
        t[fill[k]] = s[fill[k]];
    }
    if (cache.count(t) == 0 || cache[s] + 1ll < cache[t]) {

      cache[t] = cache[s] + 1ll;

      if (t == "WWWBBB  " && cache[s] == 2) {
        dbg(s);
        dbg(t);
      }
      solve(t, cache);
    }
  }
}
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  s += "  ";
  t += "  ";
  map<string, ll> cache;
  cache[s] = 0;
  queue<string> que;
  que.push(s);
  while (que.size()) {
    string node = que.front();
    que.pop();
    vector<int> vacant, fill;
    rep(i, node.size()) {
      if (node[i] == ' ')
        vacant.push_back(i);
      else
        fill.push_back(i);
    }
    rep(i, fill.size() - 1) {
      if (fill[i] + 1 != fill[i + 1])
        continue;
      int j = i + 1;
      string next_node(node.size(), ' ');
      rep(k, fill.size()) {
        if (k == i)
          next_node[vacant[0]] = node[fill[i]];
        else if (k == j)
          next_node[vacant[1]] = node[fill[j]];
        else
          next_node[fill[k]] = node[fill[k]];
      }
      if (cache.count(next_node) == 0 || cache[node] + 1ll < cache[next_node]) {
        cache[next_node] = cache[node] + 1ll;
        que.push(next_node);
      }
    }
  }
  dbg(cache);
  if (cache.count(t) == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << cache[t] << endl;
  return 0;
}
