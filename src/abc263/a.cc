#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  vector<int> cards(5);
  rep(i, 5) { cin >> cards[i]; }
  set<int> cs(cards.begin(), cards.end());
  if (cs.size() != 2) {
    cout << "No" << endl;
    return 0;
  }
  sort(cards.begin(), cards.end());
  if (cards[0] == cards[1] && cards[1] == cards[2] && cards[2] != cards[3] and
      cards[3] == cards[4]) {
    cout << "Yes" << endl;
  } else if (cards[0] == cards[1] && cards[1] != cards[2] &&
             cards[2] == cards[3] and cards[3] == cards[4]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
#endif
