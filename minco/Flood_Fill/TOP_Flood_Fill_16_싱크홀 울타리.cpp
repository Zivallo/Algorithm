#include <iostream>
using namespace std;

int map[100][100], minX, minY, maxX, maxY, maxSize = -1;
int N, M, used[100][100];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

void setXY(int nowy, int nowx) {
	for (int i = 0; i < 4; i++) {
		int ny = nowy + drY[i];
		int nx = nowx + drX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (map[ny][nx] == 0) continue;
		if (used[ny][nx] == 1) continue;
		if (ny < minY) minY = ny;
		if (ny > maxY) maxY = ny;
		if (nx < minX) minX = nx;
		if (nx > maxX) maxX = nx;
		used[ny][nx] = 1;
		setXY(ny, nx);
	}
}
int getSize(int nowy, int nowx) {
	minY = nowy, minX = nowx, maxY = nowy, maxX = nowx;
	setXY(nowy, nowx);
	return (maxY - minY + 3) * 2 + (maxX - minX + 3) * 2 - 4;
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (used[y][x] == 1)continue;
			if (map[y][x] == 0) continue;
			int size = getSize(y, x);
			if (maxSize < size) maxSize = size;
		}
	}
	cout << maxSize;
	return 0;
}