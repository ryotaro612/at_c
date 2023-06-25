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

// #ifdef ONLINE_JUDGE
int main() {
  int n, count = 0;
  string s, res = "";
  cin >> n >> s;
  vector<bool> use(n,true);
  stack<char> stk;
  rep(i, s.size()) {
    if(s[i] == '(') {
      stk.push(s[i]);
      count++;
    }
    else if(s[i] == ')'){
      if(count) {
	count--;
	while(stk.top() !='(')
	  stk.pop();
	stk.pop();
      } else
	stk.push(s[i]);
    } else {
      stk.push(s[i]);
    }
  }
  while(stk.size()){
    res.push_back(stk.top());
    stk.pop();
  }
  reverse(begin(res), end(res));
  cout << res << endl;
  
  return 0;
}
// #endif
