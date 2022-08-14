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
  int r, c;
  cin >> r >> c;
  vector<string> sv(15);
  // for (int i = 0; i < 15; i += 2) {

  // }

  sv[0] = "###############";
  sv[1] = "#.............#";
  sv[2] = "#.###########.#";
  sv[3] = "#.#.........#.#";
  sv[4] = "#.#.#######.#.#";
  sv[5] = "#.#.#.....#.#.#";
  sv[6] = "#.#.#.###.#.#.#";
  sv[7] = "#.#.#.#.#.#.#.#";
  sv[8] = "#.#.#.###.#.#.#";
  sv[9] = "#.#.#.....#.#.#";
  sv[10] = "#.#.#######.#.#";
  sv[11] = "#.#.........#.#";
  sv[12] = "#.###########.#";
  sv[13] = "#.............#";
  sv[14] = "###############";

  if (sv[r - 1][c - 1] == '#')
    cout << "black" << endl;
  else
    cout << "white" << endl;
  return 0;
}
#endif
