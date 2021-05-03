#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> scores(9, 0);
    for(int i = 0; i < n; i++) {
        if(a[i] <= 399)
            scores[0]++;
        else if(a[i] <= 799)
            scores[1]++;
        else if(a[i] <= 1199)
            scores[2]++;
        else if(a[i] <= 1599)
            scores[3]++;
        else if(a[i] <= 1999)
            scores[4]++;
        else if(a[i] <= 2399)
            scores[5]++;
        else if(a[i] <= 2799)
            scores[6]++;
        else if(a[i] <= 3199)
            scores[7]++;
        else
            scores[8]++;
    }
    int mini = 0;
    for(int i = 0; i < 8; i++) {
        if(scores[i] != 0)
            mini++;
    }
    int maxi = scores[8];
    for(int i = 0; i < 8; i++) {
        if(scores[i] > 0)
            maxi++;
    }

    cout << max(1, mini) << " " << maxi << endl;
    return 0;
}
#endif