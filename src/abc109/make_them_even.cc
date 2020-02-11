#include<iostream>
#include "make_them_even.h"

using namespace std;

Operation::Operation(pair<int, int> f, pair<int, int> t) {
  from = f;
  to = t;
}

Answer::Answer(int nn, vector<Operation> ops) {
  n = nn;
  operations = ops;
}

Answer make_them_even(int h, int w, vector<vector<int>> a) {
  vector<Operation> ops;
  bool left_to_right = true;
  int c = 0, r = 0;
  while(true) {
    //cout << "x: " << x << " y: " << y << endl;
    if(c == w-1 && r==h-1) {
      break;
    }
    // cout << " doge@@@" << endl;
    if(left_to_right) {
      if(c<w-1) {
	// cout << "bar" << endl ;	
	if(a[r][c] % 2 == 1) {
	  //cout << "bar####" << endl ;		  
	  a[r][c] -= 1;
	  //cout << "buuu####" << x+1 << "#" << y  << endl ;		  	  	  
	  a[r][c+1] += 1;
	  // cout << w-1 << "boo" << endl ;		  
	  Operation o = Operation(make_pair(r+1, c+1), make_pair(r+1, c+1+1));
	  ops.push_back(o);
	}
	c++;
	//cout << "ueeen" << endl;
	continue;
      }
      if(a[r][c] % 2 == 1) {
	a[r][c] -= 1;
	a[r+1][c] += 1;
	Operation o = Operation(make_pair(r+1, c+1), make_pair(r+1+1, c+1));
	ops.push_back(o);
      }
      left_to_right = false;
      r++;
      continue;      
    }
    if(c > 0) {
      if(a[r][c] % 2 == 1) {
	a[r][c] -= 1;
	a[r][c-1] += 1;
	Operation o = Operation(make_pair(r+1, c+1), make_pair(r+1, c-1+1));
	ops.push_back(o);
      }
      c--;
      continue;
    }
    if(r < h-1) {
      if(a[r][c] % 2 == 1) {
	a[r][c] -= 1;
	a[r+1][c] += 1;
	Operation o = Operation(make_pair(r+1, c+1), make_pair(r+1+1, c+1));
	ops.push_back(o);
      }
      left_to_right = true;
      r++;
    }
  }

  Answer answer(ops.size(), ops);
  return answer;
}

int main() {
  int h, w;
  cin >> h;
  cin >> w;
  vector<vector<int>> a;
  for(int i=0;i<h;i++) {
    vector<int> aa;
    for(int j=0;j<w;j++) {
      int b;
      cin >> b;
      aa.push_back(b);
    }
    a.push_back(aa);
  }
  Answer answer = make_them_even(h, w, a);
  cout << answer.n << endl;
  vector<Operation> ops = answer.operations;
  for(int i=0;i<ops.size();i++) {
    cout << ops[i].from.first << " " << ops[i].from.second << " " << ops[i].to.first << " " << ops[i].to.second << endl;;
  }
}
