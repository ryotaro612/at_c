#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include "candy_distribution.h"
 
using namespace std;
 
long long candy_distribution(int n, long long m, std::vector<long long> a) {
  map<long long, long long> mp;
  long long sum = 0;
  mp[0]++;
  for(int i = 0;i < a.size();i++) {
    sum += a[i];
    mp[sum % m]++;
  }
 
  long long ans = 0;
  
  for (auto i=mp.begin(); i !=mp.end();++i) {
    // cout << "key: " << i->first << " value: " << i->second << endl;
    long long size = i->second;
    ans += (size*(size-1))/2;
  }
 
  return ans;
}
/* 
int main() {
  int n;
  long long m;
  cin >> n;
  cin >> m;
  vector<long long> a;
  for(int i=0;i<n;i++) {
    long long a_i;
    cin >> a_i;
    a.push_back(a_i);
  }
  cout << candy_distribution(n, m, a);
}
*/
