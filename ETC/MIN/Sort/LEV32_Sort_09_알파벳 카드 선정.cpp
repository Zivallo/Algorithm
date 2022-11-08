#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	int n;
	cin >> n;
	string temp = str.substr(str.size() - n, n);
	int cnt[130] = { 0, };
	for (int i = 0; i < n; i++) {
		cnt[temp[i]]++;
	}
	int max = -1;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cnt[i] > max) max = cnt[i];
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cnt[i] == max) cout << (char)i;
	}

	return 0;
}