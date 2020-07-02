#include <iostream>
#include <map>

using namespace std;

map<long long, long long> prime_factor(long long n) {
  map<long long, long long> ret;

  for(long long i = 2;i*i <= n;i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n!=1)
    ret[n] = 1;
  return ret;

}

long long div_game(long long n) {
  map<long long, long long> pf = prime_factor(n);

  long long count = 0;
  for(auto i = pf.begin(); i != pf.end(); ++i) {
    long long remove = 1;
    long long count_per_prime = i->second;
    while(remove <= count_per_prime) {
      count ++;
      count_per_prime -= remove;
      remove++;
    }
  }

  return count;
}
/*
int main() {
  long long n;
  cin >> n;
  cout << div_game(n);
}
*/
