#include<iostream>
#include<queue>

using namespace std;

long powerful_discount_tickets(int n, int m, int a[]){
  priority_queue<int> que;
  for(int i=0;i<n;i++) {
    que.push(a[i]);
  }

  while(m!=0) {
    int price = que.top();
    que.pop();
    int discounted_price = price / 2;
    que.push(discounted_price);
    m--;
  }
  unsigned long ans = 0;

  while(!que.empty()) {
    ans += que.top();
    que.pop();
  }
  return ans;
}
/*
int main () {
  int n, m;
  cin >> n >> m;
  int a[n];

  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << powerful_discount_tickets(n, m, a);
}
*/
