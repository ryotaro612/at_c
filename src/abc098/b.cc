#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, string s) {
  int res = 0;
  for(int i=0;i<n-1;i++) {
    set<char> l;
    set<char> r;
    for(int j=0;j<=i;j++) {
      l.insert(s[j]);
    }
    for(int j=i+1;j<n;j++) {
      r.insert(s[j]);
    }
    set<char> lr;
    set_intersection(l.begin(), l.end(), r.begin(), r.end(), inserter(lr, lr.end()));
    res = max(res, (int) lr.size());
  }
  return res;
}
/*
int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << solve(n, s);
}
*/
