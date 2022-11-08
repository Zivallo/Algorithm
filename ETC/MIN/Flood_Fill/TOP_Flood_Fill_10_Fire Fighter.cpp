#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
int N, minDis = 999, my, mx, ny, nx;
string map[20];
queue<Node> q;
int drY[4] = { 0,0,-1,1 };
int drX[4] = { -1,1,0,0 };

int bfs1(int sy, int sx, int ly, int lx) {
	while (!q.empty()) q.pop();
	int used[20][20] = { 0, };
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = now.y + drY[i];
			nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == '#') continue;
			if (map[ny][nx] == '$') continue;
			used[ny][nx] = 1;
			if (ny == ly && nx == lx) {
				return now.lev + 1;
			}
			q.push({ ny, nx, now.lev + 1 });
		}
	}
}
int bfs2(int sy, int sx) {
	while (!q.empty()) q.pop();
	int used[20][20] = { 0, };
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = now.y + drY[i];
			nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == '#') continue;
			used[ny][nx] = 1;
			if (map[ny][nx] == '$') {
				return now.lev + 1;
			}
			q.push({ ny, nx, now.lev + 1 });
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];
	cin >> my >> mx;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 'A') {
				int temp1 = bfs1(my, mx, y, x);
				int temp2 = bfs2(y, x);
				int temp = temp1 + temp2;
				if (temp < minDis) minDis = temp;
			}
		}
	}
	cout << minDis;

	return 0;
}