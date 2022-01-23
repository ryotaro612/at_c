#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> cards(n + 1, 0);
  vector<int> av(4 * n - 1);
  rep(i, 4 * n - 1) { cin >> av[i]; }
  rep(i, av.size()) { cards[av[i]]++; }
  for (int i = 1; i < n + 1; i++) {
    if (cards[i] < 4)
      cout << i << endl;
  }
  return 0;
}
// #endif
