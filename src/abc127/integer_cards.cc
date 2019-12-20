#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
struct Replacement {
  int bb;
  long long cc;

  bool operator>(const Replacement &another) const {
    return cc > another.cc;
  }
};

long long integer_cards(int n, int m, long long a[], int b[], long long c[]) {
  vector<long long> cc;
  for(int i=0;i<m;i++) {
    for(int j=0;j<b[i];j++) {
     cc.push_back(c[i]);
    }
  }
  long long ans = 0;
  sort(cc.begin(), cc.end(), greater<long long>());
  long long peek = 0;
  for(int i=0;i<n;i++) {
    if(peek < cc.size()) {
      if(a[i] < cc[peek]) {
	ans += cc[peek];
        peek++;
	continue;
      }
      ans += a[i];
      continue;
    } 
    ans += a[i];
  }
  /*
  vector<Replacement> bc;
  for(int i=0;i<m;i++) {
    Replacement replacement = {b[i], c[i]};
    bc.push_back(replacement);
  }
  sort(bc.begin(), bc.end(), greater<Replacement>());
  sort(a, a + n);

  */
  return ans;
}

/*
int main() {
}
*/
