#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
int N, M, cntASet, cntBSet, maxLiv = -1, used[201][201];
string map[201];
queue<Node> q;
int drY[4] = { 0,0,1,-1 };
int drX[4] = { 1,-1,0,0 };

int bfs(int yt, int xt, char target) {
	if (used[yt][xt] == 1) return 0;
	q.push({ yt,xt });
	used[yt][xt] = 1;
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] != target) continue;
			used[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> map[i];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 'A') {
				int temp = bfs(y, x, 'A');
				if (temp > 0) cntASet++;
				if (temp > maxLiv) maxLiv = temp;
			}
			if (map[y][x] == 'B') {
				int temp = bfs(y, x, 'B');
				if (temp > 0) cntBSet++;
				if (temp > maxLiv) maxLiv = temp;
			}
		}
	}
	cout << cntASet << " " << cntBSet << '\n' << maxLiv;

	return 0;
}