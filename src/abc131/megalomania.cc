#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "megalomania.h"

using namespace std;

std::string megalomania(std::vector<int> a, std::vector<int> b) {
  using Pair  = std::pair<int, int>;
  vector<Pair> works;

  for(int i = 0;i<a.size();i++) {
    works.push_back(Pair(b.at(i), a.at(i)));
  }
  sort(works.begin(), works.end());

  int consumption = 0;
  
  for(int i =0;i<works.size();i++) {
    int estimation = works.at(i).second;
    int limit = works.at(i).first;
    consumption += estimation;
    if(consumption > limit) {
      return "No";      
    }
  }
  
  return "Yes";
}

