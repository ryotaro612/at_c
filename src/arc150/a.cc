#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

void add(int i, int v, vector<int> &bit) {
  int n = bit.size();
  while (i <= n) {
    bit[i] += v;
    i += i & -i;
  }
}

int sum(int i, vector<int> &bit) {
  int res = 0;
  while (i > 0) {
    res += bit[i];
    i -= i & -i;
  }
  return res;
}

string solve(int n, int k, string &s) {
  vector<int> bit(n + 10, 0), p_bit(n + 10, 0);
  rep(i, n) {
    if (s[i] == '0')
      add(i + 1, 1, bit);
    else if (s[i] == '1') {
      add(i + 1, 1, p_bit);
    }
  }
  // rep(i, n + 1) { cout << sum(i, p_bit) << endl; }
  bool found = false;
  rep(i, n) {
    if (s[i] != '0') {
      if (i + k <= n) {
        int num_zeros = sum(i + k, bit) - sum(i, bit);
        int num_p = sum(n, p_bit) - sum(i + k, p_bit) + sum(i, p_bit);
        // cout << i << " " << sum(n, p_bit) << sum(i + k, p_bit) << sum(i,
        // p_bit)
        //      << endl;
        if (num_zeros == 0 && num_p == 0) {
          if (found) {
            // cout << "already " << i << " " << num_zeros << " " << num_p <<
            // endl;
            return "No";
          } else {
            // cout << "found " << i << " " << num_zeros << " " << num_p <<
            // endl;
            found = true;
          }
        }
      }
    }
  }
  if (found)
    return "Yes";
  else
    return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(n, k, s) << endl;
  }
  return 0;
}
#endif
