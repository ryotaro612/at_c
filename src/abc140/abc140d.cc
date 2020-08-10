#include <iostream>
#include <algorithm>
#include <cmath> 
#include <string>
typedef long long ll;
using namespace std;

ll abc140d(ll n, ll k, char faces[]) {
  ll a = 0;
  for(ll i =0;i<n;i++) {
    if(i != n-1) {
      if(faces[i] != faces[i+1]) {
	a++;
      }
    }

  }
  return n-1 - max(a - 2*k, 0LL);
}
/*
int main() {
  ll n, k;
  cin >> n >> k;
  string s;  
  cin >> s;
  char faces[n];
  for(ll i=0;i<n;i++) {
    faces[i] = s[i];
  }
  cout << abc140d(n, k, faces);
}
*/
