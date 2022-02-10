#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long candles(int n, int k, std::vector<long long> x) {
  long long answer = 400000000;

  for (int start_index = 0; start_index + k <= x.size(); start_index++) {
    long long start = x[start_index];
    long long end = x[start_index + k - 1];

    if (end <= 0) {
      answer = min(answer, -start);
      continue;
    }
    if (start < 0 && end > 0) {
      long long temp = min(2 * (-start) + end, 2 * end - start);
      answer = min(temp, answer);
      continue;
    }
    answer = min(answer, end);
  }
  return answer;
}
/*
int main() {
  int n, k;
  cin >> n;
  cin >> k;
  vector<long long> x;
  for(int i =0;i<n;i++) {
    long long j;
    cin >> j;
    x.push_back(j);
  }
  cout << candles(n, k, x);
}
*/
