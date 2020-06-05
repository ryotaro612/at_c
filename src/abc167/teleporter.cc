#include<iostream>
#include<array>
#include<vector>
using namespace std;

long long teleporter(long long n, long long k, vector<long long> a) {
  if(a[0] == 0) {
    return 1;
  }
  long long visit[n];
  for(long long i=0; i<n;i++) {
    visit[i] = 0;
  }

  visit[0] = 0;
  long long point = a[0];
  long long counter = 1;
  long long cycle = -1;
  k--;
  while(true) {
    if(k==0) {
      return point;
    }
    //cout <<  "point: " << point << endl;
    if(visit[point] != 0) {
      cycle = counter - visit[point];
      break;
    }
    visit[point] = counter;
    point = a[point];
    counter++;
    k--;
  }
  /*
  cout << "=============" << endl;
  cout << "counter: " << counter << endl;
  cout << "point: " << point << endl;
  cout << "cycle: " << cycle << endl;
  cout << "visit: " << visit[point] -1 << endl;
  cout << "k: " << k << endl;
  */
  k %= cycle;
  //cout << " div " << k << endl;
  while(true) {
    if(k==0) {
      return point + 1;
    }
    k--;
    point = a[point];
  }

  return -1;
}

int main() {
  long long n, k;
  vector<long long> a;
  cin >> n;
  cin >> k;
  for(int i=0;i<n;i++) {
    long long aa;
    cin >> aa;
    a.push_back(aa - 1);
  }
  cout << teleporter(n, k, a);
}
