#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> divisors(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i)
        res.push_back(n / i);
    }
  }
  return res;
}

int solve(int n) {
  int res = 0;
  for (int i = 1; i <= n; i += 2) {
    if ((int)divisors(i).size() == 8)
      res++;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
#endif
