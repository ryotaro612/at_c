#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;

    stack<int> st;
    ll ans = 0ll;
    for(auto c : s) {
        st.push(c - '0');
        while(true) {
            if(st.size() < 2)
                break;
            // st.size >= 2
            int a = st.top();
            st.pop();
            int b = st.top();
            // とりのぞける
            if(a != b) {
                st.pop();
                ans += 2ll;
            } else { //とりのぞけない
                st.push(a);
                break;
            }
        }
    }
    cout << ans << endl;
}
#endif