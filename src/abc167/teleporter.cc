#include<iostream>
#include<array>
#include<vector>
typedef unsigned long long  ull;
using namespace std;


ull cycle[200001];

ull teleporter(ull n, ull k, vector<ull> a) {

  for(ull i =0;i<n;i++) {
    a[i] = a[i] - 1;
  }

  ull count = 0;
  ull cur = 0;
  while(true) {
    cur = a[cur];
    count++;
    if(cur == 0) {
      break;
    }
    if(cycle[cur] != 0) {
      break;
    }
    cycle[cur] = count;
  }
  // loop point is cur.
  ull loop_size = count - cycle[cur];
  //cout << " loop size " << loop_size << endl;
  //cout << " loop point " << cur << endl;

  ull p = 0;
  while(k > 0 && p != cur) {
    p = a[p];
    k--;
  }
  if(k == 0) {
    return p + 1;
  }

  k %= loop_size;

  while(k > 0) {
    p = a[p];
    k--;
  }
  return p + 1;
}
/*
int main() {
  ull n, k;
  cin >> n;
  cin >> k;
  vector<ull> a(n);
  for(ull i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << teleporter(n, k, a);
}
*/
