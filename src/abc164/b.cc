#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int a, int b, int c, int d) {
  while (true) {
    c -= b;
    if (c <= 0) {
      return "Yes";
    }
    a -= d;
    if (a <= 0) {
      return "No";
    }
  }
  return "unreachable";
}
/*
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << solve(a, b, c, d);
}
*/