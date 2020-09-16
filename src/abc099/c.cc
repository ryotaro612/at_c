#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int c(int n) {
  int res = n;
  for(int six=0;six<=n;six++) {
    int count = 0;
    int temp = six;
    for(int i=0;temp>0;i++) {
      int p = pow(6, i);
      int cnt = ((int) (six / p)) % 6;
      temp -= cnt * p;
      count += cnt;
    }
    //cout << six << " -> " << count << endl;
    int nine = n - six;
    temp = nine;
    for(int i=0;temp>0;i++) {
      int p = pow(9, i);
      int cnt = ((int) (nine / p)) % 9;
      temp -= cnt * p;
      count += cnt;
    }
    res = min(count, res);
  }
  return res;
}
/*
int main() {
  int n;
  cin >> n;
  cout << c(n);
}
*/
