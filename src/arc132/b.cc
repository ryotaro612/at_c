#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int solve(int n, vector<int> &p) {
  if (p[0] == 1 && p[n - 1] == n)
    return 0;
  if (p[0] == n && p[n - 1] == 1)
    return 1;

  int first, last;
  rep(i, n) {
    if (p[i] == 1)
      first = i;
    if (p[i] == n)
      last = i;
  }
  if (first < last) {
    // .. 1, 5 .. -> 1, 5 .. -> 5, .. 1 -> 1,..,5
    return min(first + 2, n - first);
  } else {
    return min(first, n - first + 2);
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  cout << solve(n, p) << endl;
  return 0;
}
#endif
