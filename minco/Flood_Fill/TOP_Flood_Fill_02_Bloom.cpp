#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
int map[101][100];
queue < Node> q;
int directY[4] = { 0,0,1,-1 };
int directX[4] = { 1,-1,0,0 };
int maxLev;

int main() {
	int height, width;
	cin >> height >> width;
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;
	map[y1][x1] = 1;
	map[y2][x2] = 1;
	q.push({ y1,x1,1 });
	q.push({ y2,x2,1 });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
			if (map[ny][nx] > 0) continue;
			q.push({ ny,nx,now.lev + 1 });
			map[ny][nx] = now.lev + 1;
			maxLev = now.lev + 1;
		}
	}
	cout << maxLev;

	return 0;
}