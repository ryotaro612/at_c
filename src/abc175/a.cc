#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a(string s) {
  int ans = 0;
  int c = 0;
  for(int i = 0;i<(int) s.size();i++) {
    if(s[i] == 'R') {
      c += 1;
      ans = max(ans, c);
    } else {
      c = 0;
    }
  }
  return ans;
}
/*
int main() {
  string s;
  cin >> s;
  cout << a(s);
}
*/
