#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

void decode(int &pos, string &s, vector<bool> &adversarial, int &origin) {
  if (s[pos] == '"') {
    pos++;
    decode(pos, s, adversarial, origin);
    pos++;
    if (pos < (int)s.size() && s[pos] == 'w') {
      adversarial.push_back(true);
      pos += 2;
    } else
      adversarial.push_back(false);
  } else {
    int num = 0;
    pos += 5;
    while (pos < (int)s.size() && '0' <= s[pos] && s[pos] <= '9') {
      num *= 10;
      num += s[pos] - '0';
      pos += 1;
    }
    if (pos < (int)s.size() && s[pos] == 'w') {
      pos++;
      adversarial.push_back(true);
    } else
      adversarial.push_back(false);
    origin = num - 1;
  }
}
bool traverse(int g, int step, int origin, vector<bool> &adversarial,
              vector<unordered_set<int>> &mp, vector<vector<int>> &dp) {
  if (dp[g][step] != -1)
    return dp[g][step];
  if (step == (int)adversarial.size() - 1) {
    if (adversarial[step]) {
      if (mp[g].count(origin))
        return dp[g][step] = 1;
      else
        return dp[g][step] = 0;
    } else {
      if (mp[g].count(origin))
        return dp[g][step] = 0;
      else
        return dp[g][step] = 1;
    }
  } else {
    if (adversarial[step]) {
      for (int teki : mp[g]) {
        if (traverse(teki, step + 1, origin, adversarial, mp, dp))
          return dp[g][step] = true;
      }
      return dp[g][step] = false;
    } else {
      rep(i, size(mp)) {
        if (mp[g].count(i) == 0) {
          if (traverse(i, step + 1, origin, adversarial, mp, dp))
            return dp[g][step] = true;
        }
      }
      return dp[g][step] = false;
    }
  }
}
// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  int n, m;
  cin >> n >> m;
  vector<unordered_set<int>> mp(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    mp[--a].insert(--b);
  }
  string s;
  cin >> s;
  vector<bool> adversarial;
  int origin, pos = 0;
  decode(pos, s, adversarial, origin);
  debug(origin, adversarial);
  reverse(begin(adversarial), end(adversarial));
  vector<vector<int>> dp(n, vector<int>(size(adversarial), -1));
  int res = 0;
  rep(i, n) {
    if (traverse(i, 0, origin, adversarial, mp, dp))
      res++;
  }
  cout << res << endl;
  return 0;
}
