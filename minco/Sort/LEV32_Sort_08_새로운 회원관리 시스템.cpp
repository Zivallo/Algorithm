#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[100];

int id_check(string str1) {
	int len = str1.size();
	string arr;
	string temp1;
	string temp2 = "1";
	for (int i = 0; i < len; i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') arr += "1";
		if (str1[i] >= 'a' && str1[i] <= 'z') arr += "0";
		temp1 += "0";
		if (i > 0) temp2 += "0";
	}

	if (arr == temp1)return 2;
	else if (arr == temp2)return 1;
	else return 0;
}

void str_chage(int idx, int key) {
	int len = str[idx].size();
	if (key == 2) {
		str[idx][0] = str[idx][0] - 'a' + 'A';
		return;
	}
	if (key == 1) return;
	if (key == 0) {
		for (int i = 0; i < len; i++) {
			if (str[idx][i] >= 'a' && str[idx][i] <= 'z') {
				str[idx][i] = (str[idx][i] - 'a' + 'A');
			}
		}
		return;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	for (int i = 0; i < n; i++) {
		int key = id_check(str[i]);
		str_chage(i, key);
	}

	sort(str, str + n);

	for (int i = 0; i < n; i++) {
		cout << str[i] << '\n';
	}

	return 0;
}