#include<iostream>
using namespace std;

long long caracal_vs_monster(long long h) {

  long long current = 1;
  while(current <= h) {
    current *= 2;
  }
  return current - 1;
}
/*
int main() {
  long long h;
  cin >> h;
  cout << caracal_vs_monster(h);
}
*/
