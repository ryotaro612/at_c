#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "summer_vacation.h"

using namespace std;

// https://atcoder.jp/contests/abc137/tasks/abc137_d
int summer_vacation(int n, int m, int a[], int b[]) {
  typedef pair<int, int> day;
  priority_queue<int>  que;
  vector<day> day_vec;
  for(int i=0;i<n;i++) {
    day_vec.push_back(day(a[i], i));
  }
  sort(day_vec.begin(), day_vec.end());
  int pointer = 0;
  int ans = 0;
  for(int i=m-1; i>=0; i--) {
    int rest_day = m - i;
    while(pointer < day_vec.size() && day_vec.at(pointer).first <= rest_day) {
      int index = day_vec.at(pointer).second;
      que.push(b[index]);
      pointer++;
    }
    if (!que.empty()) {
      ans += que.top();
      que.pop();
    }
  }
  return ans;
}
