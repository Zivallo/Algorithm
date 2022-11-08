#include <iostream>
#include <queue>
#include <string>
using namespace std;

string map[8];
struct Node {
	int y, x;
	int lev;
};
queue<Node> q;
int drY[4] = { 1,-1,0,0 };
int drX[4] = { 0,0,-1,1 };
int used[8][9];

void bfs1(int sy, int sx) {
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == '_') continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,now.lev + 1 });
		}
	}
}
int bfs2(int sy, int sx) {
	int used1[8][9] = { 0, };
	while (!q.empty()) q.pop();
	q.push({ sy,sx,0 });
	used1[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) continue;
			if (used[ny][nx] == 1 || used1[ny][nx] == 2) continue;
			if (used[ny][nx] == 0 && map[ny][nx] == '#') {
				return now.lev;
			}
			used[ny][nx] = 2;
			q.push({ ny,nx,now.lev + 1 });
		}
	}
	return 99;
}

int main() {
	int minDis = 99;
	for (int y = 0; y < 8; y++) cin >> map[y];
	bfs1(7, 0);
	for (int y = 7; y >= 0; y--) {
		for (int x = 0; x < 9; x++) {
			if (used[y][x] == 1) {
				int temp = bfs2(y, x);
				if (temp < minDis) minDis = temp;
			}
		}
	}
	cout << minDis;
	return 0;
}