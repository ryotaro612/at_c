#include <iostream>
#include <queue>

using namespace std;

long long lunlun_number(int k) {
  int count = 0;
  queue<long long> que;

  for(int i=1;i<=9;i++) {
    que.push(i);
  }

  long long ans;

  while(count < k) {
    ans = que.front();
    que.pop();
    count++;
    // minus;
    if(ans % 10 != 0) {
      que.push(10*ans + (ans % 10) - 1);
    }
    que.push(10*ans + (ans % 10));

    if(ans % 10 != 9) {
      que.push(10*ans + (ans % 10) + 1);
    }
  }
  return ans;
}

/*
int main() {
  int k;
  cin >> k;

  cout << lunlun_number(k);
}
*/
