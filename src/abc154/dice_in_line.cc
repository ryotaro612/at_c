#include<iostream> 
#include "dice_in_line.h"

long double dice_in_line(long long n, long long k, vector<long double> p) {
  vector<long double> a;
  for(long long i=0;i<p.size();i++) {
    long double tmp =  (p[i] + 1)/2;
    a.push_back((i != 0 ? a[i-1] : 0) + tmp);
  }

  long double answer = 0;
  for(int i= 0;i<n-k+1;i++) {
    if(i==0) {
      answer = a[k-1];
      continue;
    }
    answer = max(answer, (a[i+k-1] - a[i-1]));
  }
  return answer;
}
/*
int main() {
  long long n, k;
  cin >> n;
  cin >> k;
  vector<long double> p;
  for(long long i = 0;i<n;i++) {
    long double pp;
    cin >> pp;
    p.push_back(pp);
  }
  double a = dice_in_line(n, k, p);
    printf("%.6lf\n", a);
}
*/
