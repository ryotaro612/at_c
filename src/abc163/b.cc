#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, vector<int> a) {
  int sum = 0;
  for (auto aa : a) {
    sum += aa;
  }
  return n >= sum ? n - sum : -1;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  cout << solve(n, m, a);
}
*/
