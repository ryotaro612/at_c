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

bool sub(string x, string y) {
  int n = x.size();
  int n_ya = 0;
  int n_xa = 0;
  int n_xb = 0;
  rep(i, n) {
    if (y[i] == 'A')
      n_ya++;
    if (x[i] == 'A')
      n_xa++;
    if (x[i] == 'B')
      n_xb++;
  }
  if (!(n_xa <= n_ya && n_xb <= n - n_ya))
    return false;
  rep(i, n) {
    if (x[i] == 'C') {
      if (n_xa < n_ya) {
        x[i] = 'A';
        n_xa++;
      } else {
        x[i] = 'B';
        n_xb++;
      }
    }
  }
  int yb  = 0, xb=0;
  rep(i, n) {
    if(x[i] == 'B')
      xb++;
    if(y[i]=='B')
      yb++;
    if(xb>yb)
      return false;
  }
  return true;
}

bool solve(string x, string y) {
  x.push_back('C');
  y.push_back('C');
  int n = x.size();
  int prev = 0;
  rep(i, n) {
    if (y[i] == 'C') {
      if (x[i] == 'C') {
        if (sub(string(begin(x) + prev, begin(x) + i),
                string(begin(y) + prev, begin(y) + i))) {
          prev = i + 1;
        } else
          return false;
      }
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  rep(_, t) {
    int n;
    string x, y;
    cin >> n >> x >> y;
    if (solve(x, y))
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
  return 0;
}
