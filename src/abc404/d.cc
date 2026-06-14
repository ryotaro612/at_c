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

ll sub(int idx, vector<ll> &cost, vector<int> freq,
       vector<vector<int>> &zoo_anim) {
  if (idx == (int)zoo_anim.size()) {
    dbg(freq);
    for (auto f : freq) {
      if (f < 2) {
        return -1;
      }
    }
    return 0;
  }
  vector<ll> cand;
  rep(i, 3) {
    auto sub_freq(freq);

    // a 動物の番号
    for (auto a : zoo_anim[idx]) {
      sub_freq[a] += i;
    }
    ll c = sub(idx + 1, cost, sub_freq, zoo_anim);
    if (0 <= c) {
      cand.push_back((ll)i * cost[idx] + c);
    }
  }

  return cand.empty() ? -1 : *min_element(cand.begin(), cand.end());
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> cv(n);
  // n x
  vector<vector<int>> zoo_anim(n);
  rep(i, n) cin >> cv[i];
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int a;
      cin >> a;
      zoo_anim[--a].push_back(i);
    }
  }
  dbg(zoo_anim);
  cout << sub(0, cv, vector<int>(m, 0), zoo_anim) << endl;

  return 0;
}
