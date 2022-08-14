#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
/*
int solve(string s) {
  priority_queue<pair<int, string>, vector<pair<int, string>>,
                 greater<pair<int, string>>>
      que;
  map<string, int> d;
  d[s] = 0;
  que.push({0, string(s)});
  while (!que.empty()) {

    pair<int, string> items = que.top();
    que.pop();
    string c = items.second;
    int cost = items.first;
    if (d.find(c) != d.end() && d[c] <= cost)
      continue;

    for (int i = 0; i < 6; i++) {
      string a = string(c);
      swap(a[i], a[i + 1]);
      if ((d.find(a) != d.end() && d[a] <= cost + 1))
        continue;
      d[a] = cost + 1;
      que.push({cost + 1, a});
      // cout << a << " " << cost + 1 << endl;
    }
  }
  return d["atcoder"];
}
*/

int solve(string s) {
  queue<pair<string, int>> que;
  map<string, int> d;
  d[s] = 0;
  que.push({string(s), 0});
  while (!que.empty()) {
    pair<string, int> items = que.front();
    que.pop();
    string c = items.first;
    int cost = items.second;
    if (d.find(c) != d.end() && d[c] < cost) {
      // cout << "f " << endl;
      continue;
    }

    for (int i = 0; i < 6; i++) {
      string a = string(c);
      swap(a[i], a[i + 1]);
      // cout << " doge " << endl;
      if (d.find(a) != d.end() && d[a] <= cost + 1)
        continue;

      d[a] = cost + 1;
      que.push({a, cost + 1});
    }
  }
  return d["atcoder"];
}

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
#endif
