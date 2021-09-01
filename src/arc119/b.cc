#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
string S, T;
#ifndef _debug
int main() {
	// Step #1. 入力
	cin >> N;
	cin >> S;
	cin >> T;
	// Step #2. a[i], b[i] を求める
	vector<int> a, b;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') a.push_back(i);
		if (T[i] == '0') b.push_back(i);
	}
	// Step #3. 場合分け
	if ((int)a.size() != (int)b.size()) {
		cout << "-1" << endl;
		return 0;
	}
	// Step #4. 答えを計算し、出力する
	int Answer = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] != b[i]) Answer += 1;
	}
	cout << Answer << endl;
	return 0;
}
#endif