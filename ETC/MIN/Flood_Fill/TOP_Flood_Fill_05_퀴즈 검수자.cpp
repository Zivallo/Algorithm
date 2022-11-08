#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
int map[101][101], used[101][101];
int H, W, R, C, Y, X, N, y, x, flag, ans;
queue<Node> q;
int drY[8] = { -3,-3,-2,-2,2,2,3,3 };
int drX[8] = { -2,2,-3,3,-3,3,-2,2 };

int main() {
	cin >> H >> W >> R >> C;
	cin >> Y >> X;
	map[Y][X] = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> y >> x;
		map[y][x] = 2;
	}
	used[R][C] = 1;
	q.push({ R,C,0 });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny<0 || nx<0 || nx>W || ny>H) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == 2) continue;
			if (map[ny][nx] == 1) {
				ans = now.lev + 1;
			}
			used[ny][nx] = 1;
			q.push({ ny,nx,now.lev + 1 });
		}
	}
	if (ans) cout << ans;
	else cout << -1;

	return 0;
}