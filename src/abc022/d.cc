#include <bits/stdc++.h>
#include <iomanip>
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

class ConvexFull {
public:
  vector<pair<ld, ld>> calc(vector<pair<ld, ld>> ps) {
    sort(begin(ps), end(ps));
    int n = ps.size();
    vector<pair<ld, ld>> cf;
    rep(i, n) {
      while (cf.size() > 1 &&
             cross(cf[cf.size() - 2], cf[cf.size() - 1], ps[i]))
        cf.pop_back();
      cf.push_back(ps[i]);
    }
    for (int i = n - 2, t = cf.size(); i >= 0; i--) {
      while ((int)cf.size() > t &&
             cross(cf[cf.size() - 2], cf[cf.size() - 1], ps[i]))
        cf.pop_back();
      cf.push_back(ps[i]);
    }
    return cf;
  }

  ld farthest_dist_pow(vector<pair<ld, ld>> &ps) {
    vector<pair<ld, ld>> convex_full = calc(vector(ps));
    ld res = 0;
    for (int i = 0; i < (int)convex_full.size(); i++) {
      for (int j = i + 1; j < (int)convex_full.size(); j++) {
        ld x = (convex_full[i].first - convex_full[j].first);
        ld y = (convex_full[i].second - convex_full[j].second);
        res = max(res, x * x + y * y);
      }
    }
    return res;
  }

private:
  bool cross(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
    return (b.first - a.first) * (c.second - b.second) -
               (c.first - b.first) * (b.second - a.second) <=
           0;
  }
};

int main() {
  int n;
  cin >> n;
  vector<pair<ld, ld>> av(n), bv(n);
  rep(i, n) {
    ld x, y;
    cin >> x >> y;
    av[i] = {x, y};
  }
  rep(i, n) {
    ld x, y;
    cin >> x >> y;
    bv[i] = {x, y};
  }
  ConvexFull cf;
  ld a = cf.farthest_dist_pow(av);
  ld b = cf.farthest_dist_pow(bv);
  ld res = sqrt(b) / sqrt(a);
  cout << fixed << setprecision(12) << res << endl;
  return 0;
}
