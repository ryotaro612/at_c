#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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
  vector<map<char, vector<int>>> g_in(n), g_out(n);
  vector<vector<ll>> dist(n, vector<ll>(n, 100000000000ll));

  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                 greater<tuple<ll, int, int>>>
      que;

  rep(r, n) {
    dist[r][r] = 0;
    que.push({0, r, r});
    rep(c, n) {
      char letter;
      cin >> letter;
      if (letter != '-') {
        dist[r][c] = r == c ? 0 : 1;
        que.push({dist[r][c], r, c});
        g_in[c][letter].push_back(r);
        g_out[r][letter].push_back(c);
      }
    }
  }
  dbg(dist);
  while (que.size()) {
    auto [d, r, c] = que.top();
    que.pop();
    if (dist[r][c] < d)
      continue;

    dbg("poped", d, r, c);
    rep(i, 26) {
      char letter = 'a' + i;
      for (auto pre : g_in[r][letter]) {
        for (auto succ : g_out[c][letter]) {
          if (d + 1ll < dist[pre][succ]) {
            dbg("update", pre, succ, letter);
            dist[pre][succ] = d + 2ll;
            que.push({dist[pre][succ], pre, succ});
          }
        }
      }
    }
  }
  rep(r, n) {
    rep(c, n) {
      if (dist[r][c] < 1000000000ll) {
        cout << dist[r][c];
      } else {
        cout << -1;
      }
      cout << " \n"[c == n - 1];
    }
  }

  return 0;
}
