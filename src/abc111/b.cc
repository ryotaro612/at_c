#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> cands = {111, 222, 333, 444, 555, 666, 777, 888, 999};
  for (auto cand : cands) {
    if (n <= cand) {
      cout << cand << endl;
      return 0;
    }
  }
  return 0;
}
//#endif
