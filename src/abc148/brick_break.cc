#include<iostream>

using namespace std;

int brick_break(int n, int a[]) {
  int ans = 0;
  int peek = 1;
  for(int i=0;i<n;i++) {
    if(a[i] != peek) {
      ans++;
      continue;
    }
    peek++;
  }
  if (peek == 1) {
    return -1;
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << brick_break(n, a);
}
*/
