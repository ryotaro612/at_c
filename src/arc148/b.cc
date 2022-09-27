#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

string flip(string s, int p_pos, int i) {

  while (p_pos <= i) {
    char c = s[i];
    if (s[p_pos] == 'p')
      s[i] = 'd';
    else
      s[i] = 'p';
    if (c == 'p')
      s[p_pos] = 'd';
    else
      s[p_pos] = 'p';

    p_pos++;
    i--;
  }
  return s;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;

  int p_pos = -1;
  rep(i, s.size()) {
    if (s[i] == 'p') {
      p_pos = i;
      break;
    }
  }
  if (p_pos == -1) {
    cout << s << endl;
    return 0;
  }
  string res = string(s);

  for (int i = p_pos; i < n; i++) {
    if (s[i] == 'p') {
      string temp = flip(s, p_pos, i);
      // cout << p_pos << " " << i << " " << temp << endl;
      if (temp < res)
        res = temp;
    }
  }
  cout << res << endl;

  return 0;
}
#endif
