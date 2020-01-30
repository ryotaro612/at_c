#include<iostream> 
#include<utility>
#include<cmath>
#include<map>
#include<vector>

using namespace std;

map<int, int> enumpr(int n) {
    map<int, int> V;
    for (int i = 2; 1LL * i*i <= n; i++) while (n%i == 0) V[i]++, n /= i;
    if (n > 1) V[n]++;
    return V;
}

long long d756(int n) {
  if(n==1)
    return 0;
  map<int, int> prims;

  for(int i=1; i<=n;i++) {
    auto ep = enumpr(i);
    for(auto iter= ep.begin();iter != ep.end();iter++) {
      prims[iter->first] += iter->second;
    }
  }
  long long counter = 0;
  /*
  for(auto iter = prims.begin();iter != prims.end();iter++) {
    cout << iter->first << " -> " << iter->second << endl;
  }
  */

  for(int i=2;i<=n;i++) {
    if(74 <= prims[i])
      counter++;
  }

  for(int i=2;i<=n;i++) {
    for(int j=2;j<=n;j++) {
      if(i != j && 14 <= prims[i] && 4 <= prims[j])
	counter++;
    }
  }
  for(int i=2;i<=n;i++) {
    for(int j=2;j<=n;j++) {
      if(i != j && 24 <= prims[i] && 2 <= prims[j])
	counter++;
    }
  }
  for(int i=2;i<=n;i++) {
    for(int j=2;j<=n;j++) {
      for(int k=j+1;k<=n;k++) {
	if (i != j && i != k && 2 <= prims[i] && 4 <= prims[j] && 4 <= prims[k])
	  counter++;
      }
    }
  }
  return counter;
}
/*
int main() {
  int n;
  cin >> n; 
  cout << d756(n);
}
*/
