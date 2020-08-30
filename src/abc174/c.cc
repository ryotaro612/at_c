#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int c(int k) {
  int ans = 1;
  int c = 7;
  set<int> exist;
  while(true) {
    c %= k;
    if(c == 0) {
      return ans;
    }
    if(exist.find(c) != exist.end()) {
      return -1;
    }
    exist.insert(c);
    c *= 10;
    c += 7;
    ans++;
  }

  return -1;
}
/*
int main() {
  int k;
  cin >> k;
  cout << c(k);
}
*/
