#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    while(true) {
        if(b >= a) {
            if(count < c) {
                b -= a;
                count++;
            } else
                break;
        } else
            break;
    }
    cout << count << endl;
    return 0;
}
#endif