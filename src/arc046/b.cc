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

int rec(ll n, ll a, ll b, vector<int> &dp, vector<int> &dp2);

int rec2(ll n, ll a, ll b, vector<int> &dp, vector<int> &dp2) {
  if (dp2[n] != -1)
    return dp2[n];
  if (n <= b)
    return dp2[n] = 1;
  for (int i = 1; i <= b; i++) {
    if (rec(n - i, a, b, dp, dp2) == 1)
      return dp2[n] = 1;
  }
  return dp2[n] = 0;
}

int rec(ll n, ll a, ll b, vector<int> &dp, vector<int> &dp2) {
  if (dp[n] != -1)
    return dp[n];

  if (n <= a) {
    return dp[n] = 0;
  }

  for (int i = 1; i <= a; i++) {
    if (rec2(n - i, a, b, dp, dp2) == 0)
      return dp[n] = 0;
  }
  return dp[n] = 1;
}

void simulate(ll n, ll a, ll b) {
  vector<int> dp(n + 1, -1);
  vector<int> dp2(n + 1, -1);
  cout << n << " " << rec(n, a, b, dp, dp2) << endl;
}
bool solve(ll n, ll a, ll b) {
  if (a > b) {
    return true;
  }
  if (a < b) {
    if (n <= a)
      return true;
    else
      return false;
  }
  return n % (a + 1ll) != 0;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (solve(n, a, b))
    cout << "Takahashi";
  else
    cout << "Aoki";
  cout << endl;

  // for (int i = 1; i < 30; i++) {
  //   simulate(i, 5, 5);
  // }
  return 0;
}
#endif
