#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll abc174d(string s) {
  auto length = (ll) s.size();
  ll num_w = 0;
  for(ll i =0;i<length;i++) {
    char ss = s[i];
    if(ss == 'W') {
      num_w++;
    }
  }
  ll num_move_r = 0;
  for(int i=0;i<num_w;i++) {
    char ss = s[length - 1 - i];
    if(ss == 'R') {
      num_move_r++;
    }
  }
  return num_move_r;
}
/*
int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  cout << abc174d(s);
}
*/
