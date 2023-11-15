#include <algorithm>
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

ll solve(vector<vector<int>> &counter) {
  bool ok = true;
  rep(i, 4) {
    rep(j, 4) {
      if (i != j)
        ok = ok && counter[i][j] == 0;
    }
  }
  if (ok)
    return 0;

  ll res = 0ll;
  rep(i, 4) {
    rep(j, 4) {
      if (i != j) {
        ll move = min(counter[i][j], counter[j][i]);
        res += move;
        counter[i][j] -= move;
        counter[j][i] -= move;
        counter[i][i] += move;
        counter[j][j] += move;
      }
    }
  }
  if (res)
    return res + solve(counter);

  vector<int> ptn = {0, 1, 2, 3};
  do {
    ll move = min({counter[ptn[0]][ptn[1]], counter[ptn[2]][ptn[0]],
                   counter[ptn[1]][ptn[2]]});
    if (move) {
      counter[ptn[0]][ptn[1]] -= move;
      counter[ptn[2]][ptn[0]] -= move;
      counter[ptn[0]][ptn[0]] += move;
      counter[ptn[2]][ptn[1]] += move;
      return move + solve(counter);
    }
  } while (next_permutation(begin(ptn), end(ptn)));
  rep(i, 4) { dbg(counter[i]); }

  rep(i, 4) {
    rep(j, 4) {
      rep(k, 4) {
        if (i != j && j != k && k != i && counter[i][j] && counter[k][i]) {
          ll move = min(counter[i][j], counter[k][i]);
          counter[i][j] -= move;
          counter[k][i] -= move;
          counter[i][i] += move;
          counter[k][j] += move;
	  return move + solve(counter);
        }
      }
    }
  }

  assert(false);
}
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) {
    cin >> av[i];
    av[i]--;
  }
  vector<int> bv(av);
  sort(begin(bv), end(bv));
  vector<vector<int>> counter(4, vector<int>(4));
  rep(i, n) { counter[bv[i]][av[i]]++; }
  cout << solve(counter) << endl;
  return 0;
}
