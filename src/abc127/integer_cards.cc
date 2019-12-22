#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
using namespace std;

// http://drken1215.hatenablog.com/entry/2019/06/15/021000
long long integer_cards(int n, int m, long long a[], int b[], long long c[]) {
  vector<pair<long long, int>> aa;
  for(int i=0; i<n;i++) {
    aa.push_back(make_pair(a[i], 1));
  }
  for(int i=0;i<m;i++) {
    aa.push_back(make_pair(c[i], b[i]));
  }
  sort(aa.begin(), aa.end(), greater<pair<long long, int>>());
  int cons = 0;
  long long ans = 0;
  int index = 0;
  while(cons < n) {
    int size = n - cons > aa[index].second ? aa[index].second : n - cons;
    //cout << "index: " << index << ", item: " << aa[index].first << ", " << "size:" << size << endl;
    ans += aa[index].first * size;
    index++;
    cons += size;
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  long long a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  int b[m];
  long long c[m];
  for(int i =0;i<m;i++) {
    cin >> b[i];
    cin >> c[i];
  }
  auto ans = integer_cards(n, m, a, b, c);
  cout << ans;
}
*/
