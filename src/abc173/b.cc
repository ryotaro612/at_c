#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void b(int n, vector<string> s) {
  int ac = 0, wa = 0, tle = 0, re=0;
  for(int i=0;i<n;i++) {
    if(s[i] == "AC") {
      ac++;
    }
    if(s[i] == "WA") {
      wa++;
    }
    if(s[i] == "TLE") {
      tle++;
    }
    if(s[i] == "RE") {
      re++;
    }
  }
  cout << "AC x " << ac << endl;
  cout << "WA x " << wa << endl;
  cout << "TLE x " << tle << endl;
  cout << "RE x " << re;
}
/*
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++) {
    cin >> s[i];
  }
  b(n, s);
}
*/
