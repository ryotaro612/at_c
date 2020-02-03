#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long long> divisor(long long m) {
  vector<long long> items; 
  for(long long i =1;i*i <= m;i++) {
    if(m % i == 0) {
      items.push_back(i);

      if(i*i != m) {
	items.push_back(m / i);
      }
    }
  }
  sort(items.begin(), items.end(), greater<long long>());
  return items;
}

long long partition(long long n, long long m) {
  vector<long long> divisors = divisor(m);
  long long answer = -1;
  for(auto iter = divisors.begin(); iter != divisors.end(); iter++) {
    long long a = *iter;
    if(m >= a * n) {
      answer = a;
      break;
    }
  }
  return answer;
}
/*
int main() {
  long long n, m;
  cin >> n;
  cin >> m;
  cout << partition(n, m);
}
*/
