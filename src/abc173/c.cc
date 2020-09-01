#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int c(int h, int w, int k, vector<string> cc) {
  int res = 0;
  for(int i=0; i<(1<<h); i++) {
    for(int j=0; j<(1<<w);j++) {
      int count = 0;
      for(int a=0;a<h;a++) {
	for(int b =0;b<w;b++) {
	  if( !(j & (1 << b)) && !(i & (1 << a)) && cc[a][b] == '#') {
	    count++;
	  }
	}
      }
      if(count ==k) {
	res++;
      }
    }
  }
  return res;
}
/*
int main() {

  int h, w, k;
  cin >> h >> w >> k;
  vector<string> cc(h);
  for(int i=0;i<h;i++) {
      cin >> cc[i];
  }
  cout << c(h, w, k, cc);
}
*/
