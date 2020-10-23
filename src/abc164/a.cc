#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int s, int w) {
  return w < s ? "safe" : "unsafe";
}
/*
int main() {
  int s, w;
  cin >> s >> w;
  cout << solve(s, w);
}
*/