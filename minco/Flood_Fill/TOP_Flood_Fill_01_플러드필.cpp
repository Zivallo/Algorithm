#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
int map[5][5];
queue<Node>q;
int directY[4] = { 0,0,-1,1 };
int directX[4] = { -1,1,0,0 };

int main() {
	int y, x;
	cin >> y >> x;
	map[y][x] = 1;
	q.push({ y,x,1 });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (map[ny][nx] > 0) continue;
			q.push({ ny,nx,now.lev + 1 });
			map[ny][nx] = now.lev + 1;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}