#include <iostream>
using namespace std;

char map[10][10];
int cnt, n;

int isExistY(int y, int x) {
	for (int i = 0; i < n / 2; i++) {
		if (map[y + i][x] != map[y + n - i - 1][x]) return 0;
	}
	return 1;
}
int isExistX(int y, int x) {
	for (int i = 0; i < n / 2; i++) {
		if (map[y][x + i] != map[y][x + n - i - 1]) return 0;
	}
	return 1;
}

int main() {
	for (int t = 1; t <= 10; t++) {
		cnt = 0;
		cin >> n;
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				cin >> map[y][x];
			}
		}
		for (int y = 0; y <= 8 - n; y++) {
			for (int x = 0; x < 8; x++) {
				if (isExistY(y, x)) cnt++;
			}
		}
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x <= 8 - n; x++) {
				if (isExistX(y, x)) cnt++;
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}