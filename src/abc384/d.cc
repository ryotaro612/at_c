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

bool sub(ll s, int i, vector<ll> &prefix, map<ll, bool> &mp) {
  return mp[prefix[i] + s];
}
int main() {
  ll n, s;
  cin >> n >> s;
  vector<ll> av(n);
  vector<ll> prefix(n + 1, 0);
  map<ll, bool> mp;
  // mp[0] = true;
  rep(i, n) {
    cin >> av[i];
    prefix[i + 1] += av[i] + prefix[i];
    mp[prefix[i + 1]] = true;
  }
  
  if (s <= prefix[n]) {
    if (mp[s]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
    return 0;
  }
  if (s % prefix[n] == 0) {
    cout << "Yes\n";
    return 0;
  }
  ll sum = 0;
  sum = (s / prefix[n]) * prefix[n];
  int right = 0;
  
  while (true) {
    if (sum + av[right] == s) {
      cout << "Yes\n";
      return 0;
    } else if (sum + av[right] < s) {
      sum += av[right];
      right++;
      right %= n;
    } else {
      break;
    }
  }
  dbg("doge");

  for (ll left = 1; left < n; left++) {
    sum -= av[left - 1];
    while (true) {
      if (sum + av[right] == s) {
        cout << "Yes\n";
        return 0;
      } else if (sum + av[right] < s) {
        sum += av[right];
        right++;
        right %= n;
      } else
		break;
    }
  }
  cout << "No\n";

  return 0;
}
