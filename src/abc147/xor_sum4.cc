#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;
/**
2^60 = 1152921504606846976
 */
long long xor_sum4(int n, long long a[]) {
  long long divider = 1000000007;
  vector<bitset<60>> ba;
  long long ans = 0;
  for(int i=0;i<n;i++) {
    bitset<60> b = a[i];
    ba.push_back(b);
    // cout << b << endl;
  }
  for(int i=0;i<60;i++) {
    long long count_zero = 0;
    long long count_one = 0;
    for(int j=0;j<ba.size();j++) {
      bitset<60> b = ba[j];
      if (b[i] == 0)
	count_zero++;
      else
	count_one++;
    }
    // cout << i << " -> one: " << count_one << ", zero: " << count_zero << endl;
    /*
    long long adder = (count_one * count_zero) * pow(2, i);
    adder = adder % divider;
    ans += adder;
    */
    ans += (((count_one * count_zero) % divider) * ((1LL << i) % divider)) % divider;
    ans = ans % divider;
    // cout << ans << endl;
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  long long a[n];
  for(int i =0;i<n;i++) {
    cin >> a[i];
  }
  auto ans = xor_sum4(n, a);
  cout << ans;
}
*/
