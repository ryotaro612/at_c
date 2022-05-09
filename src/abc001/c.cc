#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

pair<string, int> solve(int deg, int dis);
/*
int main() {
    int deg, dis;
    cin >> deg >> dis;
    pair<string, int> res = solve(deg, dis);
    cout << res.first << " " << res.second << endl;
}
*/

const string s[] = {"N",   "NNE", "NE",  "ENE", "E",   "ESE", "SE",  "SSE", "S",
                    "SSW", "SW",  "WSW", "W",   "WNW", "NW",  "NNW", "N"};
const int a[] = {25,   155,  335,  545,  795,  1075, 1385,
                 1715, 2075, 2445, 2845, 3265, 20000};
pair<string, int> solve(int deg, int dis) {

  int i = 0;
  while (deg * 10 >= 1125 + 2250 * i)
    ++i;

  int j = 0;
  while (dis * 10 >= a[j] * 6)
    ++j;

  if (j == 0)
    return make_pair("C", j);
  else
    return make_pair(s[i], j);
}
