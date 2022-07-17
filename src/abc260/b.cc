#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<int> av(n), bv(n);
  rep(i, n) { cin >> av[i]; }
  rep(i, n) { cin >> bv[i]; }
  vector<bool> pass(n, false);
  vector<pair<int, int>> people(n);
  rep(i, n) { people[i] = {av[i], -i}; }
  sort(people.begin(), people.end(), greater<pair<int, int>>());
  rep(i, x) { pass[-people[i].second] = true; }

  people = vector<pair<int, int>>();
  rep(i, n) {
    if (pass[i] == false) {
      people.push_back({bv[i], -i});
    }
  }
  sort(people.begin(), people.end(), greater<pair<int, int>>());
  rep(i, y) { pass[-people[i].second] = true; }

  people = vector<pair<int, int>>();
  rep(i, n) {
    if (pass[i] == false) {
      people.push_back({av[i] + bv[i], -i});
    }
  }
  sort(people.begin(), people.end(), greater<pair<int, int>>());
  rep(i, z) { pass[-people[i].second] = true; }

  rep(i, n) {
    if (pass[i]) {
      cout << i + 1 << endl;
    }
  }

  return 0;
}
#endif
