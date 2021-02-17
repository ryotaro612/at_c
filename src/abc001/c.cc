#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

pair<string, int> solve(int deg, int dis) {
    string first;
    deg *= 10;
    if(deg >= 1125 && deg < 3375) {
        first = "NNE";
    } else if(deg >= 3375 && deg < 5625) {
        first = "NE";
    } else if(deg >= 5625 && deg < 7875) {
        first = "ENE";
    } else if(deg >= 7875 && deg < 10125) {
        first = "E";
    } else if(deg >= 10125 && deg < 12375) {
        first = "ESE";
    } else if(deg >= 12375 && deg < 14625) {
        first = "SE";
    } else if(deg >= 14625 && deg < 16875) {
        first = "SSE";
    } else if(deg >= 16875 && deg < 19125) {
        first = "S";
    } else if(deg >= 19125 && deg < 21375) {
        first = "SSW";
    } else if(deg >= 21375 && deg < 23625) {
        first = "SW";
    } else if(deg >= 23625 && deg < 25875) {
        first = "WSW";
    } else if(deg >= 25875 && deg < 28125) {
        first = "W";
    } else if(deg >= 28125 && deg < 30375) {
        first = "WNW";
    } else if(deg >= 30375 && deg < 32625) {
        first = "NW";
    } else if(deg >= 32625 && deg < 34875) {
        first = "NNW";
    } else {
        first = "N";
    }
    int second;
    if(dis >= 0 && dis <= 12) {
        return make_pair("C", 0);
    } else if(dis >= 18 && dis <= 90) {
        return make_pair(first, 1);
    } else if(dis >= 96 && dis <= 198) {
        return make_pair(first, 2);
    } else if(dis >= 204 && dis <= 324) {
        return make_pair(first, 3);
    } else if(dis >= 330 && dis <= 474) {
        return make_pair(first, 4);
    } else if(dis >= 480 && dis <= 642) {
        return make_pair(first, 5);
    } else if(dis >= 648 && dis <= 828) {
        return make_pair(first, 6);
    } else if(dis >= 834 && dis <= 1026) {
        return make_pair(first, 7);
    } else if(dis >= 1032 && dis <= 1242) {
        return make_pair(first, 8);
    } else if(dis >= 1248 && dis <= 1464) {
        return make_pair(first, 9);
    } else if(dis >= 1470 && dis <= 1704) {
        return make_pair(first, 10);
    } else if(dis >= 1710 && dis <= 1956) {
        return make_pair(first, 11);
    } else if(dis >= 1962) {
        return make_pair(first, 12);
    }
    return make_pair(first, second);
}
/*
int main() {
    int deg, dis;
    cin >> deg >> dis;
    pair<string, int> res = solve(deg, dis);
    cout << res.first << " " << res.second << endl;
}
*/