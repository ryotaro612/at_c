#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<string> s) {
  map<string, int> mp;
  ll res = 0;
  for (auto ss : s) {
    if (mp[ss] == 0) {
      res++;
      mp[ss] = 1;
    }
  }
  return res;
}
/*
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cout << solve(n, s);
}
*/