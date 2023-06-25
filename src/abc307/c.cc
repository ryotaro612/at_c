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

vector<pair<int, int>> to_ary(vector<string> &m) {
  vector<pair<int, int>> blacks;
  for (int i = 0; i < int(m.size()); i++) {
    for (int j = 0; j < int(m[0].size()); j++) {
      if (m[i][j] == '#')
        blacks.push_back({i, j});
    }
  }
  return blacks;
}
vector<set<pair<int, int>>> match(vector<pair<int, int>> &av,
                                  vector<pair<int, int>> &xv) {
  set<pair<int, int>> xs(begin(xv), end(xv));
  vector<set<pair<int, int>>> res;
  rep(i, xv.size()) {
    int dr = xv[i].first - av[0].first;
    int cr = xv[i].second - av[0].second;
    set<pair<int, int>> found;
    bool ok = true;
    rep(j, av.size()) {
      pair<int, int> p = {av[j].first + dr, av[j].second + cr};
      if (xs.count(p) == 0) {
        ok = false;
      } else {
        found.insert(p);
      }
    }
    if (ok)
      res.push_back(found);
  }
  return res;
}

// #ifdef ONLINE_JUDGE
int main() {
  int ha, wa, hb, wb, hx, wx;
  vector<string> am, bm, xm;
  cin >> ha >> wa;
  am.resize(ha);
  rep(i, ha) cin >> am[i];
  cin >> hb >> wb;
  bm.resize(hb);
  rep(i, hb) { cin >> bm[i]; }
  cin >> hx >> wx;
  xm.resize(hx);
  rep(i, hx) cin >> xm[i];
  vector<pair<int, int>> aa = to_ary(am), ba = to_ary(bm), xa = to_ary(xm);
  debug(aa, ba, xa);
  set<pair<int, int>> xs = set(begin(xa), end(xa));

  vector<set<pair<int, int>>> as = match(aa, xa), bs = match(ba, xa);
  debug(as.size(), as);
  debug(bs);
  for (auto a : as) {
    for (auto b : bs) {
      set<pair<int, int>> temp(a);
      temp.insert(begin(b), end(b));
      if (xs == temp) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
#endif
