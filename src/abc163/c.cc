#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int n, vector<int> a) {
  vector<int> res(n, 0);
  for (int i = 0; i < n - 1; i++) {
    res[a[i] - 1]++;
  }
  return res;
}
/*
int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  vector<int> res = solve(n, a);
  for (auto r : res) {
    cout << r << endl;
  }
}
*/