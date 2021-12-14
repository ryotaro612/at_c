#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    int n = s.size(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            string temp = string(s.begin() + i, s.begin() + j);
            //cout << temp << endl;
            bool ok = true;
            for(auto c: temp) {
                if(!(c == 'A' || c == 'C' || c == 'G' || c == 'T'))
                    ok = false;
            }
            if(ok)
                res = max(res, (int) temp.size());

        }
    }
    cout << res << endl;
    return 0;
}
#endif