#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string b(string s) {
  int len = (int) s.size();
  ll sum = 0;
  for(int i = 0; i< len; i++) {
    sum += (ll ((char) s[i] - '0'));
  }
  if(sum % 9 == 0) {
    return "Yes";
  }
  return "No";
}
/*
int main() {
  string n;
  cin >> n;
  cout << b(n);
}
*/
