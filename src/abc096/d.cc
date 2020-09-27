#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> take_primes(int n) {
  vector<bool> is_prime(n+1, true);
  vector<int> primes;
  is_prime[0] = is_prime[1] = false;
  for(int i=2;i<=n;i++) {
    if(is_prime[i]) {
      primes.push_back(i);
      for(int j= i*2;j<=n;j+=i) {
	is_prime[j] = false;
      }
    }
  }
  return primes;
}

vector<int> solve(int n) {
  vector<int> primes = take_primes(55555);
  vector<int> res;
  for(auto p: primes) {
    if(p % 5 == 1) {
      res.push_back(p);
    }
    if((int) res.size() == n) {
      break;
    }
  }
  return res;
}
/*
int main() {

  int n;
  cin >> n;
  auto res = solve(n);
  int len = res.size();
  for(int i=0;i<len;i++) {
    cout << res[i];
    if(i != len-1) 
      cout << " "; 
  }
}
*/
