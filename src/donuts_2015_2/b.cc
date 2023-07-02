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

// #ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> av(n), bm(m);
  rep(i, n) cin >> av[i];
  vector<vector<int>> cm(m);
  rep(i, m) {
    int c;
    cin >> bm[i] >> c;
    rep(_, c) {
      int d;
      cin >> d;
      cm[i].push_back(--d);
    }
  }
  int res = 0;
  rep(i, 1 << n) {
    set<int> members;
    rep(j, n) {
      if (i & (1 << j))
        members.insert(j);
    }
    if (members.size() != 9)
      continue;
    int sub_res = 0;
    for (auto member : members)
      sub_res += av[member];
    rep(j, m) {
      int count = 0;
      rep(k, cm[j].size()) {
	if(members.count(cm[j][k]))
	  count++;
      }
      if(count >=3)
	sub_res += bm[j];
    }
    res = max(res, sub_res);
    
  }
  cout << res << endl;
  return 0;
}
// #endif
