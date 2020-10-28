#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string n) {
  for (char c : n) {
    if (c == '7') {
      return "Yes";
    }
  }
  return "No";
}
/*
int main() {
  string n;
  cin >> n;
  cout << solve(n);
}
*/