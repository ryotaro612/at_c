#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, string t) {
  if(s.size() + 1 != t.size()) {
    return "No";
  }
  for(int i=0;i<(int) s.size(); i++) {
    if(s[i] != t[i]) {
      return "No";
    }
  }
  return "Yes";
}
/*
int main() {
  string s;
  string t;
  cin >> s >> t;
  cout << solve(s, t);
}
*/
