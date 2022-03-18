#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<char> candies(n);
  for (int i = 0; i < n; i++) {
    cin >> candies[i];
  }
  if (find(candies.begin(), candies.end(), 'Y') == candies.end())
    cout << "Three";
  else
    cout << "Four";
  cout << endl;
  return 0;
}
//#endif
