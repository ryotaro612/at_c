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
int main() {
  int n;
  cin >> n;

  vector<vector<int>> potions(n + 1);
  vector<int> tv(n), xv(n);
  set<int> res;
  rep(i, n) { cin >> tv[i] >> xv[i]; }
  rep(i, n) {
    if (tv[i] == 1) {
      potions[xv[i]].push_back(i);
    } else {
      if (potions[xv[i]].size()) {
        res.insert(potions[xv[i]].back());
        potions[xv[i]].pop_back();
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  int max_k = 0;
  int k = 0;
  rep(i, n) {
    if (tv[i] == 1 && res.contains(i)) {
      k++;
      max_k = max(k, max_k);
    } else if (tv[i] == 2) {
      k--;
    }
  }
  cout << max_k << endl;
  vector<int> bin;
  rep(i, n) {
    if (tv[i] == 1 && res.contains(i))
      bin.push_back(1);
    else if(tv[i]==1)
      bin.push_back(0);
  }
  rep(i, bin.size()) { cout << bin[i] << " \n"[(int)bin.size() - 1 == i]; }
  // int i = 0;
  // for (auto e : res) {
  //   cout << e << " \n"[i == (int)res.size() - 1];
  //   i++;
  // }

  return 0;
}
