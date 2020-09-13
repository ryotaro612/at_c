#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int c(int x, int n, vector<int> p) {
  set<int> ban;
  for(auto i: p) {
    ban.insert(i);
  }

  for(int i=0;i<x;i++) {
    int minus = x-i;
    if(ban.find(minus) == ban.end()) {
      return minus;
    }
    int plus = x + i;
    if(ban.find(plus) == ban.end()) {
      return plus;
    }
  }
  return 0;
}
/*
int main() {
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  for(int i= 0;i<n;i++) {
    cin >> p[i];
  }
  cout << c(x, n, p);
}
*/
