#include<iostream>

using namespace std;
long long prediction_and_restriction(
    int n, int k, int r, int s, int p, char t[]) {
  char ans[100000] = {'0'};
  for(int i=0;i<k;i++) {
    int peek = i;
    while(peek < n) {
      char that = t[peek];
      char ideal;
      if(t[peek] == 'r') {
	ideal = 'p';
      } else if(t[peek] == 's') {
	ideal = 'r';
      } else {
	ideal = 's';
      }
      if(peek == i || ans[peek - k] != ideal){
	ans[peek] = ideal;
	peek += k;
	continue;
      }
      if(peek + k >= n) {
	ans[peek] = that;
	peek += k;
	continue;
      }
      if(ans[peek -k] == 'r' && t[peek+k] == 'r') {
	ans[peek] = 's';
      } else if(ans[peek -k] == 'r' && t[peek+k] == 's') {
	ans[peek] = 'p';
      } else if(ans[peek -k] == 'r' && t[peek+k] == 'p') {
	ans[peek] = 'p';
      } else if(ans[peek -k] == 's' && t[peek+k] == 'r') {
	ans[peek] = 'r';
      } else if(ans[peek -k] == 's' && t[peek+k] == 's') {
	ans[peek] = 'p';
      } else if(ans[peek -k] == 's' && t[peek+k] == 'p') {
	ans[peek] = 'r';
      } else if(ans[peek -k] == 'p' && t[peek+k] == 'r') {
	ans[peek] = 's';
      } else if(ans[peek -k] == 'p' && t[peek+k] == 's') {
	ans[peek] = 's';
      } else if(ans[peek -k] == 'p' && t[peek+k] == 'p') {
	ans[peek] = 'r';
      }
      peek += k;
      continue;
    }
  }
  long long rtn = 0;
  for(int i=0; i< n; i++) {
    if(t[i] == 'r' && ans[i] == 'p') {
      rtn += p;
    }
    if(t[i] == 's' && ans[i] == 'r') {
      rtn += r;
    }
    if(t[i] == 'p' && ans[i] == 's') {
      rtn += s;
    }
  }

  return rtn;
}
/*
int main() {
  int n,k, r, s, p;
  cin >> n;
  cin >> k;
  cin >> r;
  cin >> s;
  cin >> p;
  cin.get();
  char t[n];
  for(int i=0;i<n;i++) {
    t[i] = cin.get();
  }
  cout << prediction_and_restriction(n, k, r, s, p, t);
}
*/
