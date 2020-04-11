#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

vector<int> line_plus_plus(int n, int x, int y) {
  
  vector<int> ans(n-1, 0);

  for(int i=1; i<=n-1; i++) {
    for(int j=i+1;j<=n;j++) {
      int k = min(min(abs(i-j), abs(i-x)+1 + abs(y-j)), abs(i-y) + 1 + abs(x-j));
      //cout << i << ", " << j << " -> " << k << endl;
      ans[k-1] = ans[k-1] +1;
    }
  }

  return ans;
}

/*
int main() {
  int n, x, y;

  cin >> n;
  cin >> x;
  cin >> y;

  vector<int> ans = line_plus_plus(n, x, y);

  for(int i = 0; i<ans.size();i++) {
    cout << ans[i];
    if(i != ans.size() - 1) {
      cout << endl;
    }
  }
}
*/
