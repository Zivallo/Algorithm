#include <iostream>
using namespace std;

int N, M, y3, x1, y2, x2;
int map[1100][1100];
int acc[1100][1100];
int drY[3] = { -1,0,-1 };
int drX[3] = { 0,-1,-1 };
int hap[3] = { 1,1,-1 };

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			acc[y][x] = map[y][x];
			for (int i = 0; i < 3; i++) {
				int ny = y + drY[i];
				int nx = x + drX[i];
				if (ny < 0 || nx < 0) continue;
				acc[y][x] = acc[y][x] + hap[i] * acc[ny][nx];
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> y3 >> x1 >> y2 >> x2;
		int ans = acc[y2 - 1][x2 - 1];
		if ((y3 - 2) >= 0) {
			ans = ans - acc[y3 - 2][x2 - 1];
		}
		if ((x1 - 2) >= 0) {
			ans = ans - acc[y2 - 1][x1 - 2];
		}
		if ((y3 - 2) >= 0 && (x1 - 2) >= 0) {
			ans = ans + acc[y3 - 2][x1 - 2];
		}
		cout << ans << "\n";
	}

	return 0;
}