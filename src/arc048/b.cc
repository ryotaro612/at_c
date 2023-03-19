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
  vector<int> ih(n);
  // rate,
  map<int, vector<int>> count_hands;
  vector<pair<int, int>> rate_i(n);
  rep(i, n) {
    int r, h;
    cin >> r >> h;
    if (count_hands.find(r) == count_hands.end()) {
      count_hands[r] = vector<int>(3, 0);
    }
    count_hands[r][--h]++;
    rate_i[i] = {r, i};
    ih[i] = h;
  };
  sort(rate_i.begin(), rate_i.end());
  int offset = 0;
  vector<vector<int>> res(n, vector<int>(3, 0));
  for (auto [rate, i] : rate_i) {
    while (count_hands.begin()->first < rate) {
      offset += count_hands.begin()->second[0];
      offset += count_hands.begin()->second[1];
      offset += count_hands.begin()->second[2];
      count_hands.erase(count_hands.begin());
    }

    res[i][0] += offset;
    res[i][1] += n - offset - count_hands[rate][0] - count_hands[rate][1] -
                 count_hands[rate][2];
    if (ih[i] == 0) {
      res[i][0] += count_hands[rate][1];
      res[i][1] += count_hands[rate][2];
      res[i][2] += count_hands[rate][0] - 1;
    } else if (ih[i] == 1) {
      res[i][0] += count_hands[rate][2];
      res[i][1] += count_hands[rate][0];
      res[i][2] += count_hands[rate][1] - 1;
    } else if (ih[i] == 2) {
      res[i][0] += count_hands[rate][0];
      res[i][1] += count_hands[rate][1];
      res[i][2] += count_hands[rate][2] - 1;
    }
  }
  rep(i, res.size()) {
    cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
  }

  return 0;
}
#endif
