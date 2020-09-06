#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int b(string s, string t) {
  int len = (int) s.size();
  int count = 0;
  for(int i=0;i<len;i++) {
    if(s[i] != t[i]) {
      count++;
    }
  }
  return count;
}
/*
int main() {
  string s, t;
  cin >> s; 
  cin >> t;
  cout << b(s, t);
}
*/
