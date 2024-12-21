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

vector<ll> sub(set<ll> &st, ll from, ll to) {
  vector<ll> f;
  auto iter = st.lower_bound(from);
  while (iter != end(st)) {
    if (*iter <= to) {
      f.push_back(*iter);
    } else
      break;
    iter++;
  }
  for (auto ff : f) {
    st.erase(ff);
  }
  return f;
}
int main() {
  ll n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  vector<ll> xv(n), yv(n), cv(m);
  vector<char> dv(m);
  rep(i, n) cin >> xv[i] >> yv[i];
  rep(i, m) cin >> dv[i] >> cv[i];
  unordered_map<ll, set<ll>> xmap, ymap;
  rep(i, n) {
    xmap[xv[i]].insert(yv[i]);
    ymap[yv[i]].insert(xv[i]);
  }
  // rep(i, n) {
  //   dbg(xmap[xv[i]].size());
  //   dbg(ymap[yv[i]].size());
  // }    
  set<pair<int, int>> res;
  rep(i, m) {
    // set<ll> f;
    dbg(sx, sy);
    vector<ll> temp;
    if (dv[i] == 'U') {
      // auto iter = lower_bound(begin(xmap[sx]), end(xmap[sx]), sy);
      // while (iter != end(xmap[sx])) {
      //   if (*iter <= sy + cv[i]) {
      //     f.insert(*iter);
      //   } else
      //     break;
      // }
      // for (auto ff : f) {
      //   res.insert({sx, ff});
      //   xmap[sx].erase(ff);
      // }
      temp = sub(xmap[sx], sy, sy + cv[i]);
      for (auto e : temp)
        res.insert({sx, e});
      sy += cv[i];
    } else if (dv[i] == 'D') {
      temp = sub(xmap[sx], sy - cv[i], sy);
      for (auto e : temp)
        res.insert({sx, e});
      sy -= cv[i];
    } else if (dv[i] == 'L') {
      temp = sub(ymap[sy], sx - cv[i], sx);
      for (auto e : temp)
        res.insert({e, sy});
      sx -= cv[i];
    } else {
      temp = sub(ymap[sy], sx, sx + cv[i]);
      for (auto e : temp)
        res.insert({e, sy});
      sx += cv[i];
    }
  }
  dbg(res);

  // rep(i, n) {
  //   dbg(xmap[xv[i]].size());
  //   dbg(ymap[yv[i]].size());
  // }  

  cout << sx << " " << sy << ' ' << res.size() << endl;
  return 0;
}
