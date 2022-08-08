#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
char map[20][20];
int N, M, a, b;
int drY[4] = { 0,0,-1,1 };
int drX[4] = { -1,1,0,0 };
queue<Node> q;

int bfs(int yt, int xt, char target) {
	int used[20][20] = { 0, }, ans = 0;
	q.push({ yt,xt,0 });
	used[yt][xt] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == 'x') continue;
			if (map[ny][nx] == target) ans = now.lev + 1;
			used[ny][nx] = 1;
			q.push({ ny,nx,now.lev + 1 });

		}
	}
	return ans;
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
			if (map[y][x] == 'S') {
				a = bfs(y, x, 'C');
			}
			if (map[y][x] == 'C') {
				b = bfs(y, x, 'D');
			}
		}
	}
	cout << a + b;
	return 0;
}