#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
string map[50];
int N, M, sy, sx, used[50][50];
queue<Node> q;
int drY[8] = { -1,-1,-1,0,0,1,1,1 };
int drX[8] = { -1,0,1,-1,1,-1,0,1 };

void bfs(int sy, int sx) {
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;
	if (map[sy][sx] == 'M') {
		map[sy][sx] = 'X';
		return;
	}
	int cnt = 0;
	for (int j = 0; j < 8; j++) {
		int ny1 = sy + drY[j];
		int nx1 = sx + drX[j];
		if (ny1 < 0 || nx1 < 0 || ny1 >= N || nx1 >= M) continue;
		if (map[ny1][nx1] == 'M') {
			if (used[ny1][nx1] > 0) continue;
			used[ny1][nx1] = 1;
			cnt++;
		}
		if (map[ny1][nx1] == 'B') {
			if (used[ny1][nx1] > 0) continue;
			used[ny1][nx1] = 1;
			for (int j = 0; j < 8; j++) {
				int ny2 = ny1 + drY[j];
				int nx2 = nx1 + drX[j];
				if (ny2 < 0 || nx2 < 0 || ny2 >= N || nx2 >= M) continue;
				used[ny2][nx2] = 1;
			}
		}
	}
	if (cnt != 0) map[sy][sx] = cnt + 48;
	else map[sy][sx] = 'B';

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (map[now.y][now.x] == 'M') {
			map[now.y][now.x] = 'X';
			return;
		}

		for (int i = 0; i < 8; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (used[ny][nx] > 0) continue;
			int cnt = 0;
			for (int j = 0; j < 8; j++) {
				int ny1 = ny + drY[j];
				int nx1 = nx + drX[j];
				if (ny1 < 0 || nx1 < 0 || ny1 >= N || nx1 >= M) continue;
				if (map[ny1][nx1] == 'M') {
					if (used[ny1][nx1] > 0) continue;
					cnt++;
				}
			}
			used[ny][nx] = 1;
			if (cnt != 0) {
				map[ny][nx] = cnt + 48;
			}
			else {
				q.push({ ny,nx,now.lev + 1 });
				map[ny][nx] = 'B';
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> map[i];
	cin >> sy >> sx;

	bfs(sy, sx);

	for (int y = 0; y < N; y++) cout << map[y] << '\n';


	return 0;
}