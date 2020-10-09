#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Res {
  int h, w;
  vector<vector<char>> m;

  Res(int hh, int ww, vector<vector<char>> mm) {
    h = hh;
    w = ww;
    m = mm;
  }
};

Res solve(int a, int b) {
  int h = 100;
  int w = 100;
  //int h = 12;
  //int w = 10;
  int aa = 1, bb = 1;
  vector<vector<char>> m(h);
  for (int i = 0; i < h / 2 - 1; i++) {
    m[i] = vector<char>(w);
    for (int j = 0; j < w; j++) {
      if (aa < a && i % 2 == 0 && j % 2 == 0) {
        m[i][j] = '.';
        aa++;
      } else {
        m[i][j] = '#';
      }
    }
  }
  m[h / 2 - 1] = vector<char>(w);
  m[h / 2] = vector<char>(w);
  for (int i = 0; i < w; i++) {
    m[h / 2 - 1][i] = '#';
    m[h / 2][i] = '.';
  }
  for (int i = h / 2 + 1; i < h; i++) {
    m[i] = vector<char>(w);
    for (int j = 0; j < w; j++) {
      if (bb < b && i % 2 == 1 && j % 2 == 0) {
          m[i][j] = '#';
          bb++;
      } else {
          m[i][j] = '.';
      }
    }
  }
  return Res(h, w, m);
}
/*
int main() {
  int a, b;
  cin >> a >> b;
  Res r = solve(a, b);
  cout << r.h << " " << r.w << endl;
  for (auto v : r.m) {
    for (auto vv : v) {
      cout << vv;
    }
    cout << endl;
  }
}
*/