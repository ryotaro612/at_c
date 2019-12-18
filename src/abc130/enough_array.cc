#include <iostream>
#include <vector>
#include "enough_array.h"

using namespace std;

long long enough_array(int a[], int n, int k) {
  long long answer = 0;
  for(int l=0;l<n;l++) {
    int r = l;
    int sum = 0;

    while(r<n) {
      sum += a[r];
      if(sum >= k) {
	answer += n - r;
	break;
      }
      r++;
    }
  }
  return answer;
}
