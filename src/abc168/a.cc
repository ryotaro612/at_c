#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n) {
  int d = n % 10;
  if(d == 3) {
    return "bon";
  }
  if(d == 0 || d == 1 || d == 6 || d == 8 ) {
    return "pon";
  }
  return "hon";
}
/*
int main() {
  int n;
  cin >> n;
  cout << solve(n);
}
*/
