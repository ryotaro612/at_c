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

pair<ll, int> find_val(int a, vector<pair<ll, int>> &pars) {
  if (pars[a].second < 0) {
    return {0, a};
  }
  auto p = find_val(pars[a].second, pars);
  return pars[a] = {pars[a].first + p.first, p.second};
}
bool is_same_group(int a, int b, vector<pair<ll, int>> &pars) {
  return find_val(a, pars).second == find_val(b, pars).second;
}

void unite(int a, int b, ll d, vector<pair<ll, int>> &pars) {
  if (is_same_group(a, b, pars))
    return;

  auto root_a = find_val(a, pars);
  auto root_b = find_val(b, pars);
  pars[root_a.second].second += pars[root_b.second].second;
  pars[root_b.second].second = root_a.second;
  pars[root_b.second].first = root_a.first - d - root_b.first;
}
int main() {
  int n, q;
  cin >> n >> q;
  vector<pair<ll, int>> pars(n);
  rep(i, n) { pars[i] = {0, -1}; }
  vector<int> res;
  rep(i, q) {
    int a, b;
    ll d;
    cin >> a >> b >> d;
    --a;
    --b;
    if (is_same_group(a, b, pars)) {
      auto val_a = find_val(a, pars);
      auto val_b = find_val(b, pars);
      if (val_a.first - val_b.first == d) {
        res.push_back(i + 1);
      }
    } else {
      unite(a, b, d, pars);
      res.push_back(i+1);
    }
  }
  rep(i, res.size()) { cout << res[i] << " \n"[i == (int)res.size() - 1]; }
  return 0;
}
/**
    if (mp.contains(a)) {
      if (mp.contains(b)) {
        if (mp[a].second == mp[b].second) {
          if (mp[a].first - mp[b].first == d)
            res.push_back(i + 1);
        } else {
          if(groups[mp[a].second].size() < groups[mp[b].second].size()) {
            for(auto e: groups[mp[a].second]) {


              groups[mp[b].second].push_back(e);
            }

            groups.erase(mp[a].second);
          } else {

          }
          res.push_back(i+1);
        }
      } else {
        mp[b] = {mp[a].first - d, mp[a].second};
        groups[mp[a].second].push_back(b);
        res.push_back(i + 1);
      }
    } else {
      if (mp.contains(b)) {
        mp[a] = {mp[b].first + d, mp[b].second};
        groups[mp[b].second].push_back(a);
        res.push_back(i + 1);
      } else {
        mp[a] = {0, a};
        mp[b] = {-d, a};
        res.push_back(i + 1);
        groups[a].push_back(a);
        groups[a].push_back(b);
      }
    }*/
