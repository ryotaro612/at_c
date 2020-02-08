#include <iostream>
#include <cmath>
#include "robot_arms.h"

Answer::Answer() {
  m = 0;
  vector<long long> dd;
  d = dd;
  vector<vector<char>> ww;
  w = ww;
}

Answer::Answer(long long mm, vector<long long> dd, vector<vector<char>> ww) {
  m = mm;
  d = dd;
  w = ww;
}

bool Answer::operator== (const Answer & lhs) const {
  if(m == lhs.m && d == lhs.d && w == lhs.w)
    return true;
  return false;
}

long long Answer::get_m() {
  return m;
}

vector<long long> Answer::get_d() {
  return d;
}

vector<vector<char>> Answer::get_w() {
  return w;
}

Answer robot_arms(long long n, vector<long long> x, vector<long long> y) {
  Answer a;
  vector<long long> u, v;
  int bit = abs((x[0] + y[0]) % 2);
  for(long long i=0; i<x.size(); i++) {
    if(abs(((x[i] + y[i]) % 2)) != bit) {
      return a;
    }
    u.push_back(x[i] + y[i]);
    v.push_back(x[i] - y[i]);
  }
  vector<long long> d;

  for(int i=1<<30;0<i;i=i>>1) {
    d.push_back(i);
  }
  if(bit == 0) {
    d.push_back(1);
  }
  /*
  for(auto iter = d.begin();iter != d.end();++iter) {
    cout << *iter << endl;
  }
  */
  vector<vector<char>> w;
  for(long long i=0;i< u.size();i++) {
    vector<char> ww;
    long long c_u = 0;
    long long c_v = 0;
    for(int j=0;j<d.size();j++) {
      //cout << "u: " << c_u << "v: " << c_v << endl;
      if(c_u <= u[i] && c_v <= v[i]) {
	    c_u += d[j];
	    c_v += d[j];
	    ww.push_back('R');
	    continue;
      }
      if(c_u <= u[i] && c_v > v[i]) {
	    c_u += d[j];
	    c_v -= d[j];
	    ww.push_back('U');
	    continue;
      }
      if(c_u > u[i] && c_v > v[i]) {
	    c_u -= d[j];
	    c_v -= d[j];
	    ww.push_back('L');
	    continue;
      }
      if(c_u > u[i] && c_v <= v[i]) {
	    c_u -= d[j];
	    c_v += d[j];
	    ww.push_back('D');
	    continue;
      }
    }
    w.push_back(ww);
  }
  return Answer(d.size(), d, w);
}
/*
int main() {
  long long n;
  cin >> n;
  vector<long long> x;
  vector<long long> y;
  for (long long i= 0;i<n;i++) {
    long long xx, yy;
    cin >> xx;
    cin >> yy;
    x.push_back(xx);
    y.push_back(yy);
  }
  Answer a = robot_arms(n, x, y);
  if(a.get_m() == 0) {
    cout << -1;
    return 0;
  }
  cout << a.get_m() << endl;
  vector<long long> d = a.get_d();
  for(int i = 0;i<d.size();i++) {
    cout << d[i];
    if(i != d.size() -1)
      cout << " ";
  }
  cout << endl;
  vector<vector<char>> w = a.get_w();
  for(long long i=0;i<w.size();i++) {
    vector<char> ww = w[i];
    for(long long j=0;j<ww.size();j++) {
      cout << ww[j];
    }
    if(i != w.size()-1){
      cout << endl;
    }
  }
}
*/
