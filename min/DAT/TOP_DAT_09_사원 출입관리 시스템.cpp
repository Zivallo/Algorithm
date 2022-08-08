#include <iostream>
#include <string>
using namespace std;

string list[10000];
int checkin[10000];

void join(int idx, string name) {
	if (list[idx] != "") {
		cout << idx << " ERROR\n";
	}
	else {
		list[idx] = name;
		cout << idx << " OK\n";
	}
	return;
}
void isIN(int idx) {
	if (list[idx] == "") cout << idx << " ERROR\n";
	else if (checkin[idx] == 0) {
		cout << idx << " " + list[idx] + " ENTER\n";
		checkin[idx] = 1;
	}
	else {
		cout << idx << " " + list[idx] + " EXIT\n";
		checkin[idx] = 0;
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int type, num;
		string name;
		cin >> type;
		if (type == 1) {
			cin >> num >> name;
			join(num, name);
		}
		if (type == 2) {
			cin >> num;
			isIN(num);
		}
	}

	return 0;
}