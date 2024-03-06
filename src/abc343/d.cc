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
  int n, t;
  cin >> n >> t;
  map<ll, int> score_freq;

  map<int, ll> player_score;
  rep(i, n) {
    player_score[i+1]= 0;
  }
  score_freq[0] = n; 
  rep(_, t) {
    int a;
    ll b;
    cin >> a >> b;
    score_freq[player_score[a]]--;
    if (score_freq[player_score[a]] == 0) {
      score_freq.erase(player_score[a]);
    }
    player_score[a] += b;
    score_freq[player_score[a]]++;
    cout << score_freq.size() << endl;
  }
  return 0;
}
