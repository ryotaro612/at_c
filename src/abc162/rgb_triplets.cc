#include<iostream>

using namespace std;
long long rgb_triplets(int n, string s) {
  if(n<3)
    return 0;
  long long r_count = 0;
  long long g_count = 0;
  long long b_count = 0;
  
  for(int i=0;i<n;i++) {
    if(s[i] == 'R')
      r_count++;
    if(s[i] == 'G')
      g_count++;
    if(s[i] == 'B')
      b_count++;
  }
  long long ans = r_count * g_count * b_count;

  for(long long i=0;i<n-1;i++) {
    for(long long k=i+1;k<n;k++) {
      if((k+i) % 2 != 0)
	continue;
      long long j = (k+i) / 2;
      //cout << i << " " << j << " " <<  k << " -> " << j-i << " " << k-j << endl;
      if(s[i] != s[j] && s[j] != s[k] && s[i] != s[k])
	ans--;
    }
  }
  return ans;
}
/*
int main() {
  int n;
  string s;

  cin >> n;
  cin >> s;

  cout << rgb_triplets(n, s);
}

*/
