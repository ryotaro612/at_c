#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string b(int x, int y) {
  for(int turtle=0;turtle<=x; turtle++) {
    if(turtle  * 4 + 2 * (x - turtle) == y) {
      return "Yes";
    }
  }
  return "No";
}
/*
int main() {
  int x, y;
  cin >> x >> y;
  cout << b(x, y);
}
*/
