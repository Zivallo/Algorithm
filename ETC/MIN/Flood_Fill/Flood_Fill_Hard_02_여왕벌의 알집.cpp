#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
int map[4][9], check[10], used[4][9];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
queue<Node> q;

int main() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			int cnt = 1;
			if (used[y][x] == 1) continue;
			q.push({ y,x });
			used[y][x] = 1;

			while (!q.empty()) {
				int nowy = q.front().y;
				int nowx = q.front().x;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = nowy + drY[i];
					int nx = nowx + drX[i];
					if (ny < 0 || nx < 0 || ny >= 4 || nx >= 9) continue;
					if (map[ny][nx] != map[y][x]) continue;
					if (used[ny][nx] == 1) continue;
					used[ny][nx] = 1;
					q.push({ ny, nx });
					cnt++;
					if (check[map[y][x]] < cnt) check[map[y][x]] = cnt;
				}
			}
		}
	}
	int max = -1, maxidx = 0;
	for (int i = 0; i < 10; i++) {
		if (max < check[i]) {
			max = check[i];
			maxidx = i;
		}
	}
	cout << max * maxidx;

	return 0;
}