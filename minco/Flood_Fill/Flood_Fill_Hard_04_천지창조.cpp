#include <iostream>
#include <queue>
#include <string>
using namespace std;

string map[8];
int used[8][9];

struct Node {
	int y, x;
	int lev;
};

queue<Node> q;

int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

void findoneperson(int y, int x)
{
	q.push({ y,x,0 });
	used[y][x] = 1;

	while (!q.empty()) {
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowLev = q.front().lev;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowy + drY[i];
			int nx = nowx + drX[i];
			int nLev = nowLev + 1;

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] != '#') continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,nLev });;
		}
	}
}
int finddistant(int y, int x)
{
	while (!q.empty()) q.pop();
	int used1[8][9] = { 0, };
	q.push({ y,x,0 });
	used1[y][x] = 1;

	while (!q.empty()) {
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowLev = q.front().lev;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowy + drY[i];
			int nx = nowx + drX[i];
			int nLev = nowLev + 1;

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) continue;
			if (used[ny][nx] == 1 || used1[ny][nx] == 1) continue;
			if (used[ny][nx] == 0 && map[ny][nx] == '#') return nowLev;
			if (map[ny][nx] != '_') continue;
			used1[ny][nx] = 1;
			q.push({ ny,nx,nLev });
		}
	}
}

int main() {
	for (int y = 0; y < 8; y++) cin >> map[y];
	findoneperson(7, 0);
	int minVal = 999;
	for (int y = 7; y >= 0; y--) {
		for (int x = 0; x < 9; x++) {
			if (used[y][x] == 1 && map[y][x] == '#') {
				int temp = finddistant(y, x);
				if (temp < 2) continue;
				if (temp < minVal) minVal = temp;
			}
		}
	}
	cout << minVal;
	return 0;
}