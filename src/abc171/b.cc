#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int b(int n, int k, vector<int> p);

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for(int i=0;i<n;i++) {
    cin >> p[i];
  }
  cout << b(n, k, p);
}

int b(int n, int k, vector<int> p) {
  sort(p.begin(), p.end());
  int sum = 0;
  for(int i=0;i<k;i++) {
    sum += p[i];
  }
  return sum;
}
