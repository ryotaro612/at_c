#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a(int d, int t, int s) {
  return s * t >= d ? "Yes" : "No";
}
/*
int main() {
  int d, t, s;
  cin >> d >> t >> s;
  cout << a(d, t, s);
}
*/
