#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int b(int n, vector<ll> l) {
  if(n <3) {
    return 0;
  }
  int ans = 0;
  // n-1, n-2, n-3;
  for(int i = 0;i<=n-3;i++) {
    for(int j=i+1;j<=n-2;j++) {
      for(int k=j+1;k<=n-1;k++) {
	if(l[i] + l[j] > l[k] && 
	    l[i] + l[k] > l[j] && 
	    l[j] + l[k] > l[i] &&
	    l[j] != l[k] &&
	    l[i] != l[k] &&
	    l[i] != l[j]
	    ) {
	  ans++;
	}
      }
    }
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> l(n);
  for(int i = 0; i<n;i++) {
    cin >> l[i];
  }
  cout << b(n, l);
}
*/
