#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

#ifndef _debug
int main() {
  int x;
  cin >> x;
  if(x >0 && x % 100 == 0)
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}
#endif