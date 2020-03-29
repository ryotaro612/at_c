#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include "string_formation.h"
using namespace std;

deque<char> string_formation(string s, int q, Query queries[]) {
  bool is_rev = false;
  deque<char> dq;
  for(int i=0;i<s.size();i++) {
    dq.push_back(s[i]);
  }
  for(int i=0;i<q;i++) {
    //cout << "=====>" << i << " " << is_rev << " " << s << " " << endl;
    Query query = queries[i];
    if(query.is_reverse()) {
      is_rev = !is_rev;
      continue;
    }
    if(query.is_head()) {
      if(is_rev) {
	dq.push_back(query.get_char());
	continue;
      }
      dq.push_front(query.get_char());
      continue;
    }
    if(is_rev) {
      dq.push_front(query.get_char());
      continue;
    }
    dq.push_back(query.get_char());
  }
  // cout << "-->" << is_rev << " " << s << endl;
  if(!is_rev) {
    return dq;
  }
  deque<char> rev_dq;
  while(!dq.empty()) {
    rev_dq.push_back(dq.back());
    dq.pop_back();
  }
  return rev_dq;
}

/*
int main () {
  string s;
  cin >> s;
  int q;
  cin >> q;
  Query queries[q];
  for(int i=0;i<q;i++) {
    int typ;
    cin >> typ;
    if(typ == 1) {
      queries[i] = Query();
      continue;
    }
    cin >> typ;
    string c;
    cin >> c;
    if(typ == 1) {
      queries[i] = Query(true, c);
      continue;
    }
    queries[i] = Query(false, c);
  }

  cout << string_formation(s, q, queries);
}
*/
