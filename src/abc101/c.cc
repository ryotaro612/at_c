#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int c(int n, int k, vector<int> a) {
  if((n-1) % (k-1) == 0) {
    return (n-1) / (k-1);
  }
  return (n-1) / (k-1);
}
/*
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }

  cout << c(n, k, a);
}
*/
