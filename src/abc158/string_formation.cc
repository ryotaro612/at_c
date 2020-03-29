#include <iostream>
#include <vector>
#include <string>
#include "string_formation.h"
using namespace std;

string string_formation(string s, int q, Query queries[]) {
  bool is_rev = false;
  for(int i=0;i<q;i++) {
    //cout << "=====>" << i << " " << is_rev << " " << s << " " << endl;
    Query query = queries[i];
    if(query.is_reverse()) {
      is_rev = !is_rev;
      continue;
    }
    if(query.is_head()) {
      if(is_rev) {
	s = s + query.get_char();
	continue;
      }
      s = query.get_char() + s;
      continue;
    }
    if(is_rev) {
      s =  query.get_char() + s;
      continue;
    }
    s = s + query.get_char();
  }
  // cout << "-->" << is_rev << " " << s << endl;
  if(is_rev) {
    string ss= "";
    for(int i=s.size() - 1;i>=0;i--) {
      ss = ss + s[i];
    }
    return ss;
  }
  return s;
}

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
