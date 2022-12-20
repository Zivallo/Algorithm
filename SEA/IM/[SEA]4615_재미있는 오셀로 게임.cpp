#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int T, N, M;
int drY[8] = { -1,-1,-1,0,0,1,1,1 };
int drX[8] = { -1,0,1,-1,1,-1,0,1 };
int map[10][10];

void getW(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int k = 0;
		for (int j = 1; j <= N; j++) {
			int ny = y + j * drY[i];
			int nx = x + j * drX[i];
			if (ny<1 || nx<1 || ny>N || nx>N)continue;
			if (map[ny][nx] == 0) break;
			if (map[ny][nx] == 1) {
				k = j;
				break;
			}
		}
		for (int j = 1; j < k; j++) {
			int ny = y + j * drY[i];
			int nx = x + j * drX[i];
			map[ny][nx] = 1;
		}
	}
}
void getB(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int k = 0;
		for (int j = 1; j <= N; j++) {
			int ny = y + j * drY[i];
			int nx = x + j * drX[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N)continue;
			if (map[ny][nx] == 0) break;
			if (map[ny][nx] == 2) {
				k = j;
				break;
			}
		}
		for (int j = 1; j < k; j++) {
			int ny = y + j * drY[i];
			int nx = x + j * drX[i];
			map[ny][nx] = 2;
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		memset(map, 0, sizeof(map));
		map[N / 2][N / 2] = 2;
		map[N / 2][(N / 2)+1] = 1;
		map[(N / 2)+1][N / 2] = 1;
		map[(N / 2)+1][(N / 2)+1] = 2;
		for (int i = 0; i < M; i++) {
			int ty, tx, c;
			cin >> ty >> tx >> c;
			map[ty][tx] = c;
			if (c == 1) getW(ty, tx);
			if (c == 2) getB(ty, tx);
		}
		int cntB = 0, cntW = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (map[y][x] == 1) cntB++;
				if (map[y][x] == 2) cntW++;
			}
		}
		int a = 0;
		cout << "#" << t << " " << cntB << " " << cntW << "\n";
	}
	return 0;
}