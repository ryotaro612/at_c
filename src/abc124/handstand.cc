#include <iostream>
#include <cmath>

using namespace std;
int shrink(int n, int start, int s[]) {
  int peek = start;
  while(peek < n) {
    if(s[peek] == 1)
      peek++;
    else
      break;
  }
  if (peek == n)
    return n;
  while(peek < n && s[peek] == 0) {
    peek++;
  }
  return peek;
}
int expand(int n, int start, int s[]) {
  int peek = shrink(n, start, s);
  while(peek < n) {
    if(s[peek] == 1)
      peek++;
    else
      break;
  }
  return peek;
}

int handstand(int n, int k, int s[]){
  int right = 0;
  for(int i=0;i<k;i++) {
    right = expand(n, right, s);
  }
  int ans = right;
  int left = 0;
  while(right < n) {
    left = shrink(n, left, s);
    right = expand(n, right, s);
    ans = max(ans, right - left);
  }

  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  int s[n];
  cin.get();
  for (int i=0;i<n;i++) {
    s[i] = cin.get() - 48;
  }
  cout << handstand(n, k, s);
}
*/
