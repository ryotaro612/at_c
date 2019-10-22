#include <vector>
#include <iostream>
#include <string>
#include "gathering_children.h"

using namespace std;


void handle_r_array(int begin_r, int pos_l, vector<int> *ans) {
  for(int i = begin_r; i < pos_l; i++) {
    int diff = pos_l - i;    
    if(diff % 2 == 0) {
      (*ans)[pos_l] += 1;
    } else {
      (*ans)[pos_l-1] += 1;
    }
  }
}
void handle_l_array(int begin_l, int end_l, vector<int> * ans) {
  for(int i=begin_l;i<=end_l;i++) {
    int diff = i - begin_l;
    if(diff % 2 == 0) {
      (*ans)[begin_l] += 1;
    } else {
      (*ans)[begin_l-1] += 1;
    }
  }
}

/**
 * https://atcoder.jp/contests/abc136/tasks/abc136_d
 */
vector<int> gathering_children(vector<char> s) {
  vector<int> ans(s.size());

  int start = 0;
  char formar_char = 'R';
  for(int i=1;i<s.size();i++) {
    if(formar_char == 'R') {
      if(s.at(i) == 'L') {
	handle_r_array(start, i, &ans);
	formar_char = 'L';
	start = i;
	if(i == s.size() - 1) {
	  ans[s.size() - 1] +=  1;
	}
      }
    } else {
      if(s.at(i) == 'R') {
	handle_l_array(start, i-1, &ans);
	start = i;
	formar_char = 'R';
      } else if (i == s.size() -1) {
	handle_l_array(start, i, &ans);
      }
    }
  }
  return ans;
}
