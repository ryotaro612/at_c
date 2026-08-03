#include <algorithm>
#include <cassert>
#include <cmath>
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

vector<ll> shieve(int n) {
  vector<bool> shieve(n, true);
  vector<ll> res;
  for (int i = 2; i < n; i++) {
    if (shieve[i]) {
      res.push_back(i);
      for (int j = i * 2; j < n; j += i)
        shieve[j] = false;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<ll> primes = shieve(500000);

  vector<ll> found;
  ll limit = 1000000000000ll;

  for (int i = 0; i < (int)primes.size() - 1; i++) {
    ll a = primes[i] * primes[i];
    ll step_a = primes[i] * primes[i];

    for (int j = i + 1; j < (int)primes.size(); j++) {
      ll step_b = primes[j] * primes[j];
      ll b = primes[j] * primes[j];

      a = step_a;
      while (a * step_b <= limit) {
        b = step_b;
        while (a * b <= limit) {
          if (0 < a * b) {
            found.push_back(a * b);
          } else {
            break;
          }
          b *= step_b;
        }
        a *= step_a;
      }
    }
  }
  set<ll> s(found.begin(), found.end());
  int q;
  cin >> q;

  dbg(s);
  rep(_, q) {
    ll a;
    cin >> a;
    dbg(a);
    auto iter = s.upper_bound(a);
    cout << *prev(iter) << endl;
  }
  return 0;
}
