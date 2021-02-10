#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> find_loop(int start, vector<int> &b) {
    vector<bool> traced((int)b.size(), false);
    int i = start;
    for(;;) {
        if(traced[i]) {
            vector<int> loop;
            loop.push_back(i);
            i = b[i];
            while(i != loop[0]) {
                loop.push_back(i);
                i = b[i];
            }
            return loop;
        }
        traced[i] = true;
        i = b[i];
    }
}

int naive(int a, int k, vector<int> &b) {
    int i = a;
    while(k != 0) {
        i = b[i];
        k--;
    }
    return i + 1;
}

int solve(int n, int a, string k, vector<int> b) {
    a--;
    for(int i = 0; i < (int)b.size(); i++) {
        b[i]--;
    }
    if((int)k.size() < 7) {
        return naive(a, atoi(k.c_str()), b);
    }
    vector<int> loop = find_loop(a, b);
    int before_enter = 0;
    int i = a;
    while(i != loop[0]) {
        i = b[i];
        before_enter++;
    }

    int mod = 0;
    for(int i = 0; i < (int)k.size(); i++) {
        mod *= 10;
        int size = k[i] - '0';
        mod += size;
        mod %= (int)loop.size();
    }
    int index = mod;
    for(int i = 0; i < before_enter; i++) {
        if(index == 0) {
            index = (int)loop.size() - 1;
        } else {
            index--;
        }
    }
    return loop[index] + 1;
}
/*
int main() {
    int n, a;
    string k;
    cin >> n >> a >> k;
    vector<int> b(n);
    for(int i = 0; i < n; i++)
        cin >> b[i];

    cout << solve(n, a, k, b) << endl;
}
*/