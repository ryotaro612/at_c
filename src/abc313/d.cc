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

int question(int i, int k) {
  dbg(i, k);
  vector<int> res;
  if (i <= k) {
    rep(j, k + 1) {
      if (i != j) {
        res.push_back(j + 1);
      }
    }
  } else {
    rep(j, k - 1) res.push_back(j + 1);
    res.push_back(i + 1);
  }
  cout << "? ";
  rep(j, res.size()) cout << res[j] << " \n"[j == (int)res.size() - 1];
  int a;
  cin >> a;
  return a;
}

bool violate(int i, int k, vector<bool> &results, vector<int> &assumption) {
  int acc = 0;
  if (i <= k) {
    rep(j, k + 1) {
      if (i != j) {
        acc += assumption[j];
      }
    }
  } else {
    rep(j, k - 1) acc += assumption[j];
    acc += assumption[i];
  }
  return (acc % 2 == 0) == results[i];
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> cache(n, -1);
  vector<bool> results(n);
  rep(i, n) results[i] = question(i, k);
  vector<int> assumption(n, 0);
  for (int i = 1; i < n; i++) {
    if (i == k + 1) {
      if (results[i] == results[k - 1])
        assumption[i] = assumption[k];
      else
        assumption[i] = 1 - assumption[k];
    } else {
      if (results[i] == results[i - 1])
        assumption[i] = assumption[i - 1];
      else
        assumption[i] = 1 - assumption[i - 1];
    }
  }
  dbg(assumption);
  rep(i, n) {
    if (violate(i, k, results, assumption)) {
      rep(j, n) { assumption[j] = 1 - assumption[j]; }
      break;
    }
  }
  cout << "! ";
  rep(i, n) { cout << assumption[i] << " \n"[i == n - 1]; }

  return 0;
}
