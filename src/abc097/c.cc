#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string solve(string s, int k) {
  vector<string> res;
  for(int i=0;i<(int) s.size();i++) {
    for(int j=1;j<=k;j++) {
      res.push_back(s.substr(i, j));
    }
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  return res[k-1];
}
/*
int main() {
  string s;
  int k;
  cin >> s >> k;
  cout << solve(s, k);
}
*/
