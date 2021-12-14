#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int a, int b, int k) {
    int count = 0;
    for(int i = 100; i >= 1; i--) {
        if(a % i == 0 && b % i == 0) {
            count++;
            if(count == k)
                return i;
        }
    }
    throw runtime_error("unreachable");
}

#ifdef ONLINE_JUDGE
int main() {
    int a, b, k;
    cin >> a >> b >> k;
    cout << solve(a, b, k) << endl;
}
#endif