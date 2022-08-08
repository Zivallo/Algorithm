#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
queue<Node> q;
int N, M;
int map[151][151], cnt, used[151][151];
int drY[4] = { 0,0,-1,1 };
int drX[4] = { -1,1,0,0 };

int bfs(int yt, int xt) {
	if (used[yt][xt] == 1) return 0;
	q.push({ yt,xt });
	used[yt][xt] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 0)continue;
			if (used[ny][nx] == 1)continue;
			used[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	return 1;
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
			if (map[y][x] == 2)
				if (bfs(y, x) == 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}