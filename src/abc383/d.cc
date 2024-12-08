
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

vector<ll> eratosthenes(int mx) {
  vector<bool> flags(mx + 1, true);
  if (flags.size() < 3)
    return vector<ll>();
  flags[0] = flags[1] = false;
  vector<ll> res;
  for (int i = 2; i < (int)flags.size(); i++) {
    if (flags[i]) {
      for (int j = i + i; j < (int)flags.size(); j += i) {
        flags[j] = false;
      }
      res.push_back(i);
    }
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll res = 0;
  vector<ll> primes = eratosthenes(2000000);
  for (auto p : primes) {
    bool ok = true;
    ll q = 1;
    rep(a, 8) {
      q *= p;
      if (n < q) {
        ok = false;
		break;
	  }

    }

    if (ok)
      res++;
  }
  int left = 0, right = 1;
  while (right + 1 < (int)primes.size() && primes[left] * primes[left] <= n &&
         primes[left] * primes[left] * primes[right] <= n &&
         primes[left] * primes[left] * primes[right] * primes[right] <= n) {
    right++;
  }

  for (; left < right; left++) {
    ll l2 = primes[left] * primes[left];
    while (right &&
           (n < l2 * primes[right] || n < l2 * primes[right] * primes[right])) {
      right--;
    }
    if (left < right) {
      res += right - left;
    }
  }
  cout << res << endl;
  return 0;
}
