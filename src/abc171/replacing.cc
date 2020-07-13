#include <vector>
#include <iostream>
#include <map>

using namespace std;
std::vector<long long> replacing(int n, int a[], int q, int b[], int c[]) {
  map<int, long long>  counter;
  long long sum = 0;
  for(int i=0;i<n;i++) {
    sum += a[i];
    counter[a[i]] += 1;
  }
  vector<long long> ans;
  for(int i=0; i<q; i++) {
    if(counter.find(b[i]) == counter.end()) {
      ans.push_back(sum);
      continue;
    }
    auto b_num = counter[b[i]];
    sum -= b_num * b[i];
    sum += b_num * c[i];
    ans.push_back(sum);
    counter[c[i]] += b_num;
    counter[b[i]] = 0;
  }

  return ans;
}
/*
int main() {
  int n, q;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cin >> q;
  int b[q];
  int c[q];
  for(int i=0;i<q;i++) {
    cin >> b[i];
    cin >> c[i];
  }
  vector<long long> v = replacing(n, a, q, b, c);
  for(long long i=0;i<q;i++) {
    cout << v[i] << endl;
  }

}
*/
