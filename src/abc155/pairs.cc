#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long pairs(int n, int k, vector<long long> a) {
  sort(a.begin(), a.end());
  auto it = lower_bound(a.begin(), a.end(), 0);
  vector<long long> minus_a(a.begin(), it);
  auto it_n = upper_bound(a.begin(), a.end(), 0);
  vector<long long> zero_a(it, it_n);
  vector<long long> plus_a(it_n, a.end());

  // マイナスか?
  if(k <= minus_a.size()*plus_a.size()) {
    cout << "===enter-minus====" << endl;
    int left = minus_a[0] * plus_a[plus_a.size() - 1];
    int right = 0;
    int mid;
    while(left +1 != right) {
      mid = (left + right) / 2;
      int count = 0;
      for(int i=minus_a.size() - 1;i>=0;i--) {
	for(int j=plus_a.size() - 1; j>=0;j--) {
	  cout << "multiple: " << minus_a[i]*plus_a[j] << endl;
	  long long mul = minus_a[i]*plus_a[j];
	  if(mul <= mid) {
	    count++;
	    continue;
	  }
	  break;
	}
      }
      cout << "left: " << left << " right: " << right << " mid: " << mid << " count: " << count << endl;
      if(count >= k) {
	right = mid;
	continue;
      }
      left = mid;
    }
    return mid;
  }

  return 0;
}

/*
int main() {
  int n, k;
  cin >> n;
  cin >> k;
  vector<long long> a;
  for(int i=0;i<n;i++) {
    long long temp;
    cin >> temp;
    a.push_back(temp);
  }
  cout << pairs(n, k, a);
}
*/
