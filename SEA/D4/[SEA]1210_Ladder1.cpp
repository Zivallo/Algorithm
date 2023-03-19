#include <iostream>
using namespace std;
int N, sx;
int m[110][110];

int search(int sx) {
	int ret = 0, x = sx, y = 99, dir = 0;
	while (y > 0) {
		if (dir != 1 && x - 1 >= 0) {
			if (m[y][x - 1] == 1) {
				x--;
				dir = 2;
				continue;
			}
		}
		if (dir != 2 && x + 1 < 100) {
			if (m[y][x + 1] == 1) {
				x++;
				dir = 1;
				continue;
			}
		}
		if (m[y - 1][x] == 1) { y--; dir = 0; }
	}
	ret = x;
	return ret;
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> N;
		for (int y = 0; y < 100; y++)for (int x = 0; x < 100; x++) {
			cin >> m[y][x];
			if (m[y][x] == 2) sx = x;
		}
		int r = search(sx);
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}