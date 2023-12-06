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

vector<int> read_bv(vector<int> &av) {
  int m = av.size();
  vector<int> bv(m);
  for (int i = 0; i < m; i++)
    cin >> bv[i];
  // ll n = 1000000000;
  // rep(i, m) {
  //   int cur = i;
  //   rep(_, n) {
  //     cur = av[cur];
  //     cur--;
  //   }
  //   bv[i] = cur + 1;
  // }
  // vector<int> cycles = {2, 3, 5, 7,  11, 13, 17, 19, 23, 9};
  // for (auto c : cycles) {
  //   dbg(n % c, c);
  // }
  return bv;
}
int main() {
  int m = 108;
  cout << m << endl;
  vector<int> av(m);
  vector<int> cycles = {4, 9, 5, 7, 11, 13, 17, 19, 23};
  // vector<int> cycles = {2, 3};
  int a = 1;
  vector<int> index;
  for (auto cycle : cycles) {
    int base = a;
    index.push_back(base - 1);
    rep(j, cycle) {
      if (j < cycle - 1)
        av[a - 1] = a + 1;
      else
        av[a - 1] = base;
      a++;
    }
  }
  for (int i = 0; i < m; i++)
    cout << av[i] << " \n"[i == m - 1];
  dbg(index);
  vector<int> remains(index.size());
  int step = 0;
  vector<int> bv = read_bv(av);
  dbg("read");
  rep(i, m) {
    if (step < (int)index.size() && index[step] == i) {
      remains[step] = bv[i] - (index[step] + 1);
      step++;
    }
  }

  ll cand = 1;
  for (;; cand++) {
    bool ok = true;
    rep(i, 5) { ok = ok && ((cand % cycles[i]) == remains[i]); }
    if (ok)
      break;
  }
  dbg(cand, remains);
  for (;; cand += 13860ll) {
    bool ok = true;
    rep(i, cycles.size()) { ok = ok && ((cand % cycles[i]) == remains[i]); }
    if (ok) {
      cout << cand << endl;
      return 0;
    }
  }

  dbg(remains);

  return 0;
}
