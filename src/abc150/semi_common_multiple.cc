#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;


ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

//オーバフローしないようにかける順番を気を付ける
ll lcm(ll x,ll y){
    return ll(x/gcd(x,y))*y;
}

long long div_count(long long a) {
  long long count =0;
  while(a % 2 == 0) {
    a = a / 2;
    count ++;
  }
  return count;
}

long long semi_common_multiple(long long n, long long m, long long a[]) {
  long long base = 1;
  long long count = div_count(a[0] / 2);
  for(int i=0;i<n;i++) {
    long long half = a[i]/2;
    if(count != div_count(half))
      return 0;
    base = lcm(half, base);
  }

  long long num = m / base; 
  if(num % 2 == 0)
    return num  / 2;
  return (num / 2) + 1;
}

/*
int main() {
  long long n, m;
  cin >> n;
  cin >> m;
  long long a[n];
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << semi_common_multiple(n, m, a);
}
*/
