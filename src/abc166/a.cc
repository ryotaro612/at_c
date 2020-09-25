#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string solve(string s) {
  string res = "";
  res.push_back('A');
  res.push_back(s == "ABC" ? 'R' : 'B');
  res.push_back('C');
  return res;
}
/*
int main() {
  string s;
  cin >> s;
  cout << solve(s);
}
*/
