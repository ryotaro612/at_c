#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;

ll chat_in_a_circle(int n, ll a[]) {
  vector<ll> b;
  for(int i=0;i<n;i++) {
    b.push_back(a[i]);
  }

  sort(b.begin(), b.end());

  ll ans = 0;
  for(int i=0;i<n-1;i++) {
    ans += b[(n-1)- ((int) ((i+1)/ 2))];
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << chat_in_a_circle(n, a);
}
*/
