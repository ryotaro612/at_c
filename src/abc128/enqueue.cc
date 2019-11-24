#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// 10,000,000 -> 1s
long long enqueue(int n, int k, long long v[]) {
  int threshold = min(n, k);
  long long ans = 0;
  for(int max_fetch=1;max_fetch<=threshold;max_fetch++) {
    for(int left = 0; left<=max_fetch;left++) {
      priority_queue<long long, vector<long long>, greater<long long>> que;      
      int right = max_fetch - left;
      long long value = 0;

      for(int i =0;i<left;i++) {
	value +=v[i];
	que.push(v[i]);
      }
      // for(int j=right-1;j>=0;j--) {
      for(int j=0;j<right;j++) {
	value += v[n-1-j];
	que.push(v[n-1-j]);
      }
      int max_enqueue = threshold - max_fetch;
      while(true) {
	if(que.empty() || que.top() >= 0 || max_enqueue <= 0) {
	  break;
	}
	auto item = que.top();
	value -= item;
	que.pop();
	max_enqueue--;
      }
      ans = max(ans, value);
    }
  }
  return ans;
}
