#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <system_error>
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
int n, t, m, res;
vector<set<int>> dislike;
vector<set<int>> groups;
void backtrack(int i) {
  if (i == n) {
    if (int(groups.size()) == t)
      res++;
    return;
  }

  rep(group, groups.size()) {
    bool insertable = true;
    for (int player : groups[group]) {
      if (dislike[i].count(player)) {
        insertable = false;
      }
    }
    if (insertable) {
      groups[group].insert(i);
      backtrack(i+1);
      groups[group].erase(i);
    }
  }
  if (int(groups.size()) < t) {
    groups.push_back({i});
    backtrack(i + 1);
    groups.pop_back();
  }
}
// #ifdef ONLINE_JUDGE
int main() {
  cin >> n >> t >> m;
  dislike.resize(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    dislike[--a].insert(--b);
    dislike[b].insert(a);
  }

  backtrack(0);
  cout << res << endl;
  return 0;
}
// #endif
