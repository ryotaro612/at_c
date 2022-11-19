#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int dp[26][1 << 16];
string sa[16];

int compute_winner(int n, int letter, int state) {
  if (dp[letter][state])
    return dp[letter][state];
  // cout << letter << " " << state << endl;
  rep(i, n) {
    if ((state & (1 << i)) && letter == sa[i][0] - 'a') {
      if (compute_winner(n, sa[i].back() - 'a', (state & ~(1 << i))) == 2) {
        return dp[letter][state] = 1;
      }
    }
  }
  return dp[letter][state] = 2;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> sa[i];
  rep(i, n) {
    int state = (1 << n) - 1;
    if (compute_winner(n, sa[i].back() - 'a', state & ~(1 << i)) == 2) {
      cout << "First" << endl;
      return 0;
    }
  }
  cout << "Second" << endl;
  return 0;
}
#endif
