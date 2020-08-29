#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b(string s, string t) {
  int ans = 1000000;
  for(int i= 0;i<= s.size()-t.size();i++) {
    int diff = 0;
    for(int j = i;j<i+t.size();j++) {
      if(s[j] != t[j-i]) {
	diff++;
      }
    }
    ans = min(ans, diff);
  }
  return ans;
}
/*
int main() {
  string s, t;
  cin >> s >> t;
  cout << b(s, t);
}
*/
