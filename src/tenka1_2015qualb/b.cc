#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
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

pair<string, int> parse_expr(string &s, int pos);

pair<string, int> parse_dictset(string &s, int pos) {
  if (s[pos + 1] == '}')
    return {"dict", pos + 2};
  pos = parse_expr(s, pos + 1).second;
  if (s[pos] == ':') {
    pos = parse_expr(s, pos + 1).second;
    while (s[pos] == ',') {
      pos = parse_expr(s, pos + 1).second;
      pos = parse_expr(s, pos + 1).second;
    }
    return {"dict", pos + 1};
  } else {
    while(s[pos] == ',') {
      pos = parse_expr(s, pos+1).second;
    }
    return {"set", pos+1};
  }
}

pair<string, int> parse_integer(string &s, int pos) {
  while (pos < int(s.size()) && '0' <= s[pos] && s[pos] <= '9')
    pos++;
  return {"integer", pos};
}

pair<string, int> parse_expr(string &s, int pos) {
  debug(pos, s[pos]);
  if (s[pos] == '{')
    return parse_dictset(s, pos);
  else
    return parse_integer(s, pos);
}

// #ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  cout << parse_expr(s, 0).first << endl;
  return 0;
}
// #endif
