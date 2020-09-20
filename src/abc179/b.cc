#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, vector<int> d, vector<int> dd) {
  int time = 0;
  for(int i=0;i<n;i++) {
    if(d[i] == dd[i]) {
      time++;
    } else {
      time = 0;
    }
    if(time == 3) {
      return "Yes";
    }
  }
  return "No";
}
/*
int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  vector<int> dd(n);
  for(int i=0;i<n;i++) {
    cin >> d[i] >> dd[i];
  }
  cout << solve(n, d, dd);
}
*/
