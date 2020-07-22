#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>
typedef long long ll;

using namespace std;

// 10,000,000 -> 1s
long long enqueue(int n, int k, long long v[]) {
  ll ans = 0;
  for (int kk=0;kk<=k;kk++) {
    for(int num_pick = 0; num_pick <= kk; num_pick++) {
      if(n < num_pick) {
	continue;
      }
      int num_remove = kk - num_pick;
      if(num_pick < num_remove) {
	continue;
      }
      for(int a = 0; a<=num_pick; a++) {
	priority_queue<ll, vector<ll>, greater<ll>> que;      
	for(int aa =0;aa<a;aa++) {
	  que.push(v[aa]);
	}
	int b= num_pick - a;
	for(int bb = 0;bb<b;bb++) {
	  que.push(v[n - 1 - bb]);
	}
	for(int i =0;i<num_remove;i++) {
	  que.pop();
	}
	ll temp = 0;
	while(!que.empty()) {
	  temp += que.top();
	  que.pop();
	}
	ans = max(ans, temp);
      }
    }
  }

  return ans;
}
/*
int main() {
  int n, k;
  cin >> n >> k;
  ll v [n];
  for(int i=0;i<n;i++) {
    cin >> v[i];
  }
  cout << enqueue(n, k, v);
}
*/
