#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node {
	int y, x;
	int lev;
};
queue<Node> q;
string map[11];
int Y, X;
int drY[5] = { -1,1,0,0 };
int drX[5] = { 0,0,-1,1 };
int check[5][2];

int Floodfill(int sy, int sx, char target) {
	int used[10][10] = { 0, };
	if (map[sy][sx] == target) {
		check[(int)(target - '0')][0] = sy;
		check[(int)(target - '0')][1] = sx;
		return 0;
	}
	q.push({ sy, sx, 0 });

	while (!q.empty()) {
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowLev = q.front().lev;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowy + drY[i];
			int nx = nowx + drX[i];
			int nLev = nowLev + 1;
			if (ny < 0 || nx < 0 || ny >= Y || nx >= X) continue;
			if (used[ny][nx] == 1 || map[ny][nx] == '#') continue;
			if (map[ny][nx] == target) {
				check[(int)(target - '0')][0] = ny;
				check[(int)(target - '0')][1] = nx;
				while (!q.empty()) q.pop();
				return nLev;
			}
			used[ny][nx] = 1;
			q.push({ ny,nx,nLev });
		}
	}
	return 0;
}

int main() {
	cin >> Y >> X;
	for (int y = 0; y < Y; y++) cin >> map[y];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += Floodfill(check[i][0], check[i][1], i + 1 + '0');
	}
	cout << sum << "ȸ";
	return 0;
}