#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;
// http://ututel.blog121.fc2.com/blog-entry-138.html
long long xor_sum4(int n, long a[]) {
  long divider = 1000000007;
  vector<bitset<60>> ba;
  long long ans = 0;
  for(int i=0;i<n;i++) {
    bitset<60> b = a[i];
    ba.push_back(b);
    // cout << b << endl;
  }
  for(int i=0;i<60;i++) {
    int count_zero = 0;
    int count_one = 0;
    for(int j=0;j<ba.size();j++) {
      bitset<60> b =  ba[j];
      if (b[i] == 0)
	count_zero++;
      else
	count_one++;
    }
    // cout << i << " -> one: " << count_one << ", zero: " << count_zero << endl;
    long adder = (count_one * count_zero) * pow(2, i);
    ans += adder;
    // cout << ans << endl;
    ans = ans % divider;
  }

  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  long a[n];
  for(int i =0;i<n;i++) {
    cin >> a[i];
  }
  auto ans = xor_sum4(n, a);
  cout << ans;
}
*/
