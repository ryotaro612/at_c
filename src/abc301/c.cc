]#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

int s_alpha[26], t_alpha[26];

#ifdef ONLINE_JUDGE
int main() {
  string s, t;
  cin >> s >> t;
  int s_a = 0, t_a = 0;
  rep(i, s.size()) {
    if (s[i] == '@')
      s_a++;
    else
      s_alpha[s[i] - 'a']++;
  }
  rep(i, t.size()) {
    if (t[i] == '@')
      t_a++;
    else
      t_alpha[t[i] - 'a']++;
  }
  int req_a = 0, req2_a = 0;
  set<char> cs = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  rep(i, 26) {
    int diff = abs(s_alpha[i] - t_alpha[i]);
    if (diff && cs.find('a' + i) == cs.end()) {
      cout << "No\n";
      return 0;
    }
    if (s_alpha[i] > t_alpha[i]) {
      req2_a += diff;
    } else if (s_alpha[i] < t_alpha[i]) {
      req_a += diff;
    }
  }

  if (req_a <= s_a && req2_a <= t_a) {
    cout << "Yes\n";
  } else
    cout << "No\n";
  return 0;
}
#endif
