#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int max_bit(long long k) {
  int counter = 0;
  while(k !=0) {
    k = k >> 1;
    counter++;
  }
  return counter;
}

long long xxor(long long n, long long k, long long a[]) {
  int k_bit_peek = max_bit(k);

  int begin = k_bit_peek;
  for(long long i=0;i<n;i++) {
    begin = max(begin, max_bit(a[i]));
  }
  // all zero
  if(begin ==0) {
    return 0;
  }
  //cout << "max_bit: " << begin << endl;
  
  long long res = 0;
  for(int i=begin; i!=-1; i--) {
    if(i != 0 && ( (k & (1LL << (i-1))) == 0)) {
      continue;
    }
    long long temp_ans = 0;
    for(int j=begin; j!=0; j--) {
      long long num_of_one = 0;
      long long flag = 1LL << (j-1);
      for(long long k = 0;k<n;k++) {
	if (a[k] & flag) {
	  num_of_one++;
	}
      }
      if(j>i) {
	if(k & flag) {
	  temp_ans += flag * (n - num_of_one);
	} else {
	  temp_ans += flag * num_of_one;
	}
      } else if (j==i) {
	//cout << "j==i " << flag * num_of_one << endl;
	temp_ans += flag * num_of_one;
      } else {
	//cout << "j<i " << flag * max(num_of_one, n-num_of_one) << endl;
	temp_ans += flag * max(num_of_one, n-num_of_one);
      }
    }
    // cout << "best: " << res << " current: " << temp_ans << " at " << i << endl;
    res = max(res, temp_ans);
  }
  return res;
}
/*
int main() {
  long long n, k;
  cin >> n;
  cin >> k;
  long long a[n];
  for(long long i=0;i<n;i++) {
    cin >> a[i]; 
  }
  cout << xxor(n, k, a);
}
*/
