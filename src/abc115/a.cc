#include <bits/stdc++.h>
using namespace std;
//D=25 なら Christmas, D=24 なら Christmas Eve, D=23 なら Christmas Eve Eve, D=22 なら Christmas Eve Eve Eve と出力するプログラムを作ってください。

#ifdef ONLINE_JUDGE
int main() {
  int d;
  cin >> d;
  string s;
  switch(d) {
  case 25:
    s = "Christmas";
    break;
  case 24:
    s = "Christmas Eve";
    break;
  case 23:
    s = "Christmas Eve Eve";
    break;
  case 22:
    s = "Christmas Eve Eve Eve";
    break;            
  }
  cout << s << endl;
}
#endif
