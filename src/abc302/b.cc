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
string m[101];
#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) cin >> m[i];
  int deltas[8][2] = {{-1, 0}, {0, 1},   {1, 0},  {0, -1},
                      {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};
  rep(r, h) {
    rep(c, w) {

      for (int *delta : deltas) {
        int i = r, j = c;
        string s = "";
        rep(k, 5) {
          if (0 <= i && i < h && 0 <= j && j < w) {
            s += m[i][j];
          }
          // cout << "(" << i << " " << j << ") ";
          i += delta[0];
          j += delta[1];
        }
        // cout << r << " " << c << " -> " << s << endl;
        if (s == "snuke") {
          i = r, j = c;
          rep(k, 5) {
            cout << i + 1 << " " << j + 1 << endl;
            i += delta[0];
            j += delta[1];
          }
          return 0;
        }
      }
    }
  }

  return 0;
}
#endif
