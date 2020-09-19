#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int k, string s) {
  string res = "";
  for(int i= 0;i<(int) s.size();i++) {
    if(i<k) {
      res.push_back(s[i]);
    } else {
      res = res + "...";
      break;
    }
  }
  return res;
}
/*
int main() {
  int k;
  string s;
  cin >> k >> s;
  cout << solve(k, s);
}
*/
