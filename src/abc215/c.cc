#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
	sort(s.begin(), s.end());
    do {
		//cout << s << endl;
        k--;
        if(k == 0) {
            cout << s << endl;
        }

    } while(next_permutation(s.begin(), s.end()));
    return 0;
}
#endif