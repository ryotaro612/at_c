#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(int h, int w, int d, vector<vector<int>> a, int q, vector<int> l, vector<int> r) {
  vector<int> loc_h(h * w + 1), loc_w(h * w + 1);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      loc_h[a[i][j]] = i + 1;
      loc_w[a[i][j]] = j + 1;
    }
  }
  vector<ll> tmp(h * w + 1, 0);
  for (int i = d + 1; i <= h * w; i++) {
    tmp[i] = tmp[i - d] + abs(loc_h[i] - loc_h[i - d]) + abs(loc_w[i] - loc_w[i - d]);
  }

  vector<ll> res(q);
  for (int i = 0; i < q; i++) {
    res[i] = tmp[r[i]] - tmp[l[i]];
  }
  return res;
}
/*
int main() {
  int h, w, d, q;

  cin >> h >> w >> d;
  vector<vector<int>> a(h, vector<int>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  cin >> q;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
  }

  for (auto z : solve(h, w, d, a, q, l, r)) {
    cout << z << endl;
  }
}
*/