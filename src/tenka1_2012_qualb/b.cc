#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    bool ok = true;
    string ans = "";
    int now = 0;
    int a = 0;
    int b = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='_') a++;
        else break;
    }
    if(n==a){
        cout<<s<<endl;
        return 0;
    }
    for(int i = n - 1;i>=0;i--){
        if(s[i]=='_') b++;
        else break;
    }
    int cnt = 0;
    if('A'<=s[0]&&s[0]<='Z'){
        cout<<s<<endl;
        return 0;
    }
    if('0'<=s[0]&&s[0]<='9'){
        cout<<s<<endl;
        return 0;
    }
    if('A'<=s[a]&&s[a]<='Z'){
        cout<<s<<endl;
        return 0;
    }
    if('0'<=s[a]&&s[a]<='9'){
        cout<<s<<endl;
        return 0;
    }
    for(int i = a;i<n-b;i++){
        if(s[i]=='_') cnt++;
    }
    for(int i = a;i<n-b;i++){
        int ni = 0;
        if('a'<=s[i]&&s[i]<='z') ni = s[i] - 'a';
        else ni = s[i] - 'A';
        if(cnt){
            if(s[i]=='_'){
                if(now) {
                    cout<<s<<endl;
                    return 0;
                }else{
                    now++;
                }
                continue;
            }
            if(now){
                if('0'<=s[i]&&s[i]<='9'){
                    cout<<s<<endl;
                    return 0;
                }
                if('A'<=s[i]&&s[i]<='Z'){
                    cout<<s<<endl;
                    return 0;
                }
                ans += ni + 'A';
                now = 0;
            }else{
                if('0'<=s[i]&&s[i]<='9'){
                    ans += s[i];
                    continue;
                }
                if('A'<=s[i]&&s[i]<='Z'){
                    cout<<s<<endl;
                    return 0;
                }
                
                ans += ni + 'a';
            }
        }else{
            if('0'<=s[i]&&s[i]<='9'){
                ans += s[i];
                continue;
            }
            if('A'<=s[i]&&s[i]<='Z'){
                ans += '_';
                ans += ni + 'a';
                continue;
            }else{
                ans += ni + 'a';
            }
        }
    }
    for(int i = 0;i<a;i++) cout<<"_";
    cout<<ans;
    for(int i = 0;i<b;i++) cout<<"_";
    cout<<endl;
}
