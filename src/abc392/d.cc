#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  if (!(cin >> n))
    return 0;

  vector<map<int, double>> kl;
  kl.reserve(n);

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    map<int, double> probs;
    for (int j = 0; j < k; ++j) {
      int e;
      cin >> e;
      probs[e] += 1.0 / k;
    }
    kl.push_back(probs);
  }

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double temp = 0.0;
      for (const auto &pair : kl[i]) {
        int e = pair.first;
        auto it = kl[j].find(e);
        if (it != kl[j].end()) {
          temp += pair.second * it->second;
        }
      }
      res = max(res, temp);
    }
  }

  cout << fixed << setprecision(15) << res << "\n";

  return 0;
}
