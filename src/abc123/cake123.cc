#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<long long> cake123(
    int x, 
    int y, 
    int z, 
    int k, 
    long long a[], 
    long long b[], 
    long long c[]) {
  sort(a, a+x, greater<long long>());
  sort(b, b+y, greater<long long>());
  sort(c, c+z, greater<long long>());

  priority_queue<long long> que;
  for(int i=0;i<x && i<k; i++) {
    for(int j=0;j<y && j<k; j++) {
      que.push(a[i] + b[j]);
    }
  }

  priority_queue<long long> que2;
  int consumed = 0;
  while(!que.empty() && consumed <= k) {
    long long item = que.top();
    for(int i=0;i<z && i<k; i++) {
      que2.push(c[i] + item);
    }
    que.pop();
    consumed++;
  }

  vector<long long> ans;
  consumed = 0;
  while(!que2.empty() && consumed++ < k) {
    ans.push_back(que2.top());
    que2.pop();
  }
  return ans;
}
/*
int main() {
  int x, y, z, k;
  cin >> x;
  cin >> y;
  cin >> z;
  cin >> k;
  long long a[x], b[y], c[z];
  for(int i=0;i<x;i++)
    cin >> a[i]; 
  for(int i=0;i<y;i++)
    cin >> b[i];
  for(int i=0;i<z;i++)
    cin >> c[i];
  vector<long long> ans = cake123(x, y, z, k, a, b, c);
  for(int i=0;i<ans.size();i++) {
    cout << ans[i];
    if(i!= (ans.size() -1))
      cout << endl;
  }
}
*/
