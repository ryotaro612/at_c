#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#ifndef _LOCAL
int main() {
    int a[5];
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    vector<int> p;
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 4; j++) {
            for(int k = j + 1; k < 5; k++) {
                p.push_back(a[i] + a[j] + a[k]);
            }
        }
    }
    sort(p.begin(), p.end(), greater<int>());
    cout << p[2] << endl;

    return 0;
}
#endif