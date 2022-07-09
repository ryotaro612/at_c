#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<pair<char, int>> build(string &s) {
  vector<pair<char, int>> sv;
  sv.push_back({s[0], 1});
  for (int i = 0; i < (int)s.size(); i++) {
    if (sv.back().first == s[i]) {
      sv[sv.size() - 1] = {s[i], sv.back().second + 1};
    } else {
      sv.push_back({s[i], 1});
    }
  }
  return sv;
}

string solve(string &s, string &t) {
  vector<pair<char, int>> sv = build(s);
  vector<pair<char, int>> tv = build(t);

  if (sv.size() != tv.size())
    return "No";
  int n = sv.size();
  rep(i, n) {
    if (sv[i].first != tv[i].first)
      return "No";
    if (sv[i].second == tv[i].second) {
      continue;
    } else if (sv[i].second > tv[i].second) {
      return "No";
    } else { // sv[i].second < tv[i].second
      if (sv[i].second == 1)
        return "No";
      else
        continue;
    }
  }
  return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
  string s, t;
  cin >> s >> t;
  cout << solve(s, t) << endl;
  return 0;
}
#endif
