#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    int number;
    if(n >= 42)
        number = n + 1;
    else
        number = n;
    char res[7];
    sprintf(res, "AGC%03d", number);
    cout << res << endl;
}
#endif