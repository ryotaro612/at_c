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
  vector<ll> sv(n), cv(n);
  rep(i, n) cin >> sv[i] >> cv[i];
  // [key val)が黒
  map<ll, ll> pointers;
  pointers[sv[0]] = sv[0] + cv[0];
  cout << pointers[sv[0]] - 1ll << endl;
  for (int i = 1; i < n; i++) {
    ll left, right;
    auto iter = pointers.upper_bound(sv[i]);
    //
    if (iter == pointers.begin()) {
      right = left = sv[i];
    } else { //
      if (sv[i] <= prev(iter)->second) {
        left = prev(iter)->first;
        right = prev(iter)->second;
      } else {
        left = right = sv[i];
      }
    }
    ll c = cv[i];
    while (true) {
      auto iter = pointers.upper_bound(right);
      if (iter == pointers.end()) {
        pointers[left] = right + c;
        cout << pointers[left] - 1ll << endl;
        break;
      } else {
        if (right + c < iter->first) {
          pointers[left] = right + c;
          cout << pointers[left] - 1ll << endl;
	  break;
        } else if (right + c == iter->first) {
	  cout << right + c - 1ll << endl;
	  pointers[left] = iter->second;
	  pointers.erase(iter->first);
	  break;
        } else { // iter->first < right + c
	  c -= iter->first - right;
	  right = iter->second;
	  pointers.erase(iter->first);
        }
      }
    }
  }
  return 0;
}
