#include <iostream>
#include <utility>

using namespace std;

pair<long long, long long> i_hate_factorization(long long x) {
  for(long long a=-118;a<=119;a++) {
    for(long long b=-119;b<=118;b++) {
      if (x == ((a * a * a * a * a) - (b * b * b * b * b))) {
	return make_pair(a, b);
      }
    }
  }
  return make_pair(-1, -1);
}

/*
int main() {
  long long x;
  cin >> x;
  auto ans = i_hate_factorization(x);
  cout << ans.first << " " << ans.second;
}
*/
