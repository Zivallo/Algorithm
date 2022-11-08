#include <iostream>
#include <string>
using namespace std;

string list;
int n;

void setList(int l, int r) {
	while (1) {
		if (list[l] == list[r]) {
			list[l] = '#';
			list[r] = '#';
		}
		else return;
		l--;
		if (l < 0 || r >= n) return;
		while (list[l] == '#') {
			l--;
			if (l < 0) return;
		}
		r++;
		if (l < 0 || r >= n) return;
		while (list[r] == '#') {
			r++;
			if (r >= n) return;
		}
		if (l < 0 || r >= n) return;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int t = 1; t <= 10; t++) {
		cin >> n >> list;
		for (int i = 0; i < (n - 1); i++) {
			if (list[i] == '#') continue;
			if (list[i] == list[i + 1]) setList(i, i + 1);
		}
		cout << "#" << t << " ";
		for (int i = 0; i < n; i++) {
			if (list[i] == '#') continue;
			cout << list[i];
		}
		cout << '\n';
	}
	return 0;
}

