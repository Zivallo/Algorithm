#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y, x;
	int lev;
};
int map[200][200], used[200][200];
int N, M, t;
queue<Node> q;
int drY[4] = { 1,-1,0,0 };
int drX[4] = { 0,0,1,-1 };

int bfs() {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == t) continue;
			if (map[ny][nx] != 0 && used[ny][nx] == 0) {
				return now.lev;
			}
			used[ny][nx] = 1;
			q.push({ ny,nx,now.lev + 1 });
		}
		int v = 10;
	}
	return 99;
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
			if (map[y][x] != 0) {
				t = map[y][x];
				break;
			}
		}
		if (t) break;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == t) {
				q.push({ y,x,0 });
				used[y][x] = 1;
			}
		}
	}
	int e = 0;
	cout << bfs();
	return 0;
}