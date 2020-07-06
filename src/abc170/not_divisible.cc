#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
// https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files
long long not_divisible(long long n, vector<long long> a) {

  sort(a.begin(), a.end());
  const long long a_max = 1000001; 
  bool div[a_max];
  memset(div, false, sizeof div);
  long long count = 0;
  if(a.size() == 1) {
    return 1;
  }
  /*
  for(auto aa = a.begin();aa != a.end();aa++) {
    cout << *aa << endl;
  }
  cout << "=========" << endl;
  */
  for(long long i=0;i<n;i++) {
    if(i==0) {
      if(a[i] != a[i+1]) {
	// cout <<  a[i]<< "!!"  << endl;
	count++;
      }
      long long aa = a[i];
      while(aa < a_max) {
	div[aa] = true;
	aa += a[i];
      }
      continue;
    }
    if(i < n-1) {
      if(a[i] != a[i-1] && a[i+1] != a[i] && !div[a[i]]) {
	//cout << a[i]<< "!!" << div[a[i]] << endl;
	count++;
      }
      if(a[i] == a[i-1]) {
	continue;
      }
      long long aa = a[i];
      while(aa < a_max) {
	/*
	if(div[aa]) {
	  break;
	}
	*/
	div[aa] = true;
	aa += a[i];
      }
      continue;
    }
    // i == n-1
    if(a[i-1] != a[i] && !div[a[i]]) {
      //cout <<  a[i]<< "!!"  << endl;
      count++;
    }
  }

  return count;
}
/*
int main() {
  long long n;
  cin >> n;
  vector<long long> a;
  for(long long i=0; i<n;i++) {
    long long aa;
    cin >> aa;
    a.push_back(aa);
  }
  cout << not_divisible(n, a);
}
*/
