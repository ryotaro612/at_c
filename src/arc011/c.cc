#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  string first, last;
  int n;
  cin >> first >> last >> n;
  set<string> ss;
  ss.insert(first);
  ss.insert(last);
  rep(i, n) {
    string s;
    cin >> s;
    ss.insert(s);
  }
  if (first == last) {
    cout << 0 << endl << first << endl << last << endl;
    return 0;
  }
  map<string, int> mp;
  int n_nodes = 0;
  for (auto &s : ss) {
    mp[s] = n_nodes++;
  }
  vector<vector<int>> g(n_nodes);
  for (auto s : ss) {
    int left = mp[s];
    rep(i, s.size()) {
      char backup = s[i];
      rep(j, 26) {
        char c = 'a' + j;
        if (s[i] != c) {
          s[i] = c;
          if (mp.find(s) != mp.end()) {
            int right = mp[s];
            g[left].push_back(right);
            g[right].push_back(left);
          }
        }
      }
      s[i] = backup;
    }
  }
  ll inf = 100000000000000ll;
  vector<ll> d(n_nodes, inf);
  d[mp[first]] = 0;
  queue<int> que;
  que.push(mp[first]);
  while (que.size()) {
    int node = que.front();
    que.pop();
    for (auto neighbor : g[node]) {
      if (d[neighbor] > d[node] + 1) {
        d[neighbor] = d[node] + 1;
        que.push(neighbor);
      }
    }
  }
  map<int, string> rev_mp;
  for (auto [k, v] : mp) {
    rev_mp[v] = k;
  }
  // rep(i, n_nodes) { cout << d[i] << rev_mp[i] << endl; }
  // cout << mp[last] << "@@ " << endl;
  if (d[mp[last]] >= inf) {
    cout << -1 << endl;
    return 0;
  }
  cout << d[mp[last]] - 1 << endl;
  int current = mp[last];
  stack<int> stk;
  stk.push(current);
  while (stk.top() != mp[first]) {
    for (int neighbor : g[stk.top()]) {
      if (d[neighbor] == d[stk.top()] - 1) {
        stk.push(neighbor);
        break;
      }
    }
  }

  while (stk.size()) {
    cout << rev_mp[stk.top()] << endl;
    stk.pop();
  }

  return 0;
}
#endif
