#include <iostream>
#include <vector>

using namespace std;


vector<int> rain_flows_into_dams(vector<int> a) {
  vector<int> ans;

  int acc = 0;
  for(int i = 0;i<a.size();i++) {
    if(i % 2 == 0) {
      acc += a.at(i);
    } else {
      acc -= a.at(i);
    }
  }
  ans.push_back(acc);
  for(int i = 0; i<a.size()-1;i++) {
    int y = ans.at(i) / 2;
    ans.push_back((a.at(i) - y)*2);
  }
  return ans;
}

