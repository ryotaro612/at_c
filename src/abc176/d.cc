#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int d(int h, int w, int ch, int cw, int dh, int dw, vector<vector<char>> s) {
  vector<vector<int>> cost(1001, vector<int>(1001, -1));

  queue<pair<int, int>> que;
  que.push(make_pair(ch-1, cw-1));

  queue<pair<int, int>> last_area;

  int current_cost = 0;
  cost[ch-1][cw-1] = 0;
  while(true) {
    while(!que.empty()) {
      pair<int, int> cur = que.front();
      que.pop();
      last_area.push(make_pair(cur.first, cur.second));

      if(dh - 1 == cur.first && dw - 1 == cur.second) {
	return current_cost;
      }

      int hh, ww;
      // top
      if(cur.first != 0) {
	hh = cur.first - 1;
	ww = cur.second;
	if(cost[hh][ww] == -1 && s[hh][ww] == '.') {
	  que.push(make_pair(hh, ww));
	  cost[hh][ww] = current_cost;
	}
      }
      // right
      if(cur.second != w-1) {
	hh = cur.first;
	ww = cur.second + 1;
	if(cost[hh][ww] == -1 && s[hh][ww] == '.') {
	  que.push(make_pair(hh, ww));
	  cost[hh][ww] = current_cost;
	}
      }
      // bottom 
      if(cur.first != h-1) {
	hh = cur.first + 1;
	ww = cur.second;
	if(cost[hh][ww] == -1 && s[hh][ww] == '.') {
	  que.push(make_pair(hh, ww));
	  cost[hh][ww] = current_cost;
	}
      }
      //  left
      if(cur.second != 0) {
	hh = cur.first;
	ww = cur.second - 1;
	if(cost[hh][ww] == -1 && s[hh][ww] == '.') {
	  que.push(make_pair(hh, ww));
	  cost[hh][ww] = current_cost;
	}
      }
    }

    current_cost++;
    while(!last_area.empty()) {
      pair<int, int> point = last_area.front();
      last_area.pop();
      int i = point.first;
      int j = point.second;
      for(int ii = i-2; ii<=i+2; ii++) {
	for(int jj = j-2; jj<=j+2; jj++) {
	  if(ii < 0 || jj < 0 || ii >= h || jj >= w) {
	    continue;
	  }
	  if(cost[ii][jj] == -1 && s[ii][jj] == '.') {
	    que.push(make_pair(ii, jj));
	    cost[ii][jj] = current_cost;
	  }
	}
      }
    }
    if(que.empty()) {
      return -1;
    }
  }
  // unreachable 
  return -1;

}
/*
int main() {
  int h, w, ch, cw, dh, dw;
  cin >> h >> w >> ch >> cw >> dh >> dw;
  vector<vector<char>> s(h);
  for(int i =0; i<h;i++) {
    s[i] = vector<char>(w);
    for(int j = 0; j < w;j++) {
      cin >> s[i][j];
    }
  }
  cout << d(h, w, ch, cw, dh, dw, s);
}
*/
