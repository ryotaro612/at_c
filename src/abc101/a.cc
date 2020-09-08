#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int a(string s) {
  int res = 0;
  int len = (int) s.size();
  for(int i=0;i<len;i++) {
    if(s[i] == '+')
      res++;
    else
      res--;
  }
  return res;
}
/*
int main() {
  string s;
  cin >> s;
  cout << a(s);
}
*/
