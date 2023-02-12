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
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  map<int, int> mp;
  int result = 0;
  for (int left = 0, right = 0; left < n; left++) {
    right = max(left, right);
    while (right < n && mp[av[right]] == 0) {
      mp[av[right++]]++;
      result = max(result, right - left);
    }
    if (right < n && mp[av[right]] > 0) {
      mp[av[left]]--;
    }
  }
  cout << result << endl;
  return 0;
}
#endif
