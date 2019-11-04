#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> preparing_boxes(vector<int> a) {
  int check[a.size()];
  int half = a.size() % 2 ? a.size() / 2 : (a.size() / 2 + 1);
  for(int i = half; i < a.size(); i++) {
    check[i+1] = a.at(i);
  }
  vector<int> ans;
  
  for(int i = half; i>=1; i--) {
    int acc = 0;
    int peek = i*2;
    while(peek <= a.size()) {
      acc += check[peek];
      peek += i;
    }
    if(a.at(i-1) == 0) {
      if(acc % 2 == 1) {
	check[i] = 1;
	ans.push_back(i);
      } else { // acc == 0
	check[i] = 0;
      }
    } else { // a.at(i-1) == 1
      if(acc % 2 == 1) {
	check[i] = 0;
      } else { // acc % 2 == 0
	check[i] = 1;
	ans.push_back(i);
      }
    }
  }
  
  reverse(ans.begin(), ans.end());
  return ans;
}


