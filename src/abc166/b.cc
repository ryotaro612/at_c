#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int k, vector<vector<int>> a) {
  vector<bool> res(n, true);
  for(auto aa: a) {
    for(auto aaa: aa) {
      res[aaa -1] = false;
    }
  }
  int count = 0;
  for(auto r: res) {
    if(r)
      count++;
  }

  return count;
}
/*
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k);
  for(int i=0;i<k;i++) {
    int d;
    cin >> d;
    a[i] = vector<int>(d);
    for(int j=0;j<d;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, k, a);
}
*/
