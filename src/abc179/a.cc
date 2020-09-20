#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
  string ss = "";
  if(s[((int) s.size()) - 1] != 's') {
    ss = s + "s";
    return ss;
  }
  ss = s + "es";
  return ss;
}
/*
int main() {
  string s;
  cin >> s;
  cout << solve(s);
}
*/
