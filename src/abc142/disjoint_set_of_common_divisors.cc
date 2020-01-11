#include <iostream>
#include <set>
#include <algorithm>
#include "disjoint_set_of_common_divisors.h"

using namespace std;


set<int> prime_factor(int n) {
  set<int> ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret.insert(i);
      n /= i;
    }
  }
  if(n != 1) ret.insert(n);
  return ret;
}

int disjoint_set_of_common_divisors(int a, int b) {
  set<int> aa = prime_factor(a);
  set<int> bb = prime_factor(b);
  set<int> merged;
  set_intersection(aa.begin(), aa.end(), bb.begin(), bb.end(), inserter(merged, merged.end()));
  return merged.size() + 1;
}
