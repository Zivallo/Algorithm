#include <iostream>
using namespace std;

int n, map[110][110], used[110][110];

int nSwap(int ty, int tx) {
	for (int y = ty + 1; y < n; y++) {
		if (map[y][tx] == 1) {
			map[ty][tx] = 0;
			map[y - 1][tx] = 1;
			return 0;
		}
		if (map[y][tx] == 2) {
			map[ty][tx] = 0;
			map[y - 1][tx] = 1;
			return 1;
		}
	}
	return 0;
}
int main() {
	for (int t = 1; t <= 10; t++) {
		cin >> n;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> map[y][x];
			}
		}
		int cnt = 0;
		for (int y = n - 1; y >= 0; y--) {
			for (int x = 0; x < n; x++) {
				if (map[y][x] == 1) cnt += nSwap(y, x);
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}