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
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(m);
  rep(i, m) { cin >> av[i]; }
  vector<ll> scores(n, 0);
  vector<vector<ll>> rest(n, vector<ll>());
  rep(i, n) {
    string s;
    cin >> s;
    scores[i] = i+1;
    rep(j, m) {
      if (s[j] == 'o') {
        scores[i] += av[j];
      } else {
	rest[i].push_back(av[j]);
      }
    }
    sort(begin(rest[i]), end(rest[i]), greater<ll>());
  }
  ll mx = *max_element(begin(scores), end(scores));
  set<int> highest_players;
  rep(i, n) {
    if (scores[i] == mx)
      highest_players.insert(i);
  }

  rep(i, n) {
    if(highest_players.count(i)) {
      if(highest_players.size() == 1) {
	cout << 0 << endl;
      } else
	cout << 1 << endl;
    } else {
      ll score = scores[i];
      rep(j, rest[i].size()) {
	score += rest[i][j];
	if(score > mx) {
	  cout << j + 1 << endl;
	  break;
	}
      }
    }
  }
  return 0;
}
