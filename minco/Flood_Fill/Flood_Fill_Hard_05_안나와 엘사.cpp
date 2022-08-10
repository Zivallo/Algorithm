#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int ey, ex, ay, ax, t;
};
int idxMagic = 4;
int N;
int aDrY[5] = { 0,0,0,-1,1 };
int aDrX[5] = { 0,-1,1,0,0 };
int eDrY[8] = { 0,0,1,-1,1,-1,-1,1 };
int eDrX[8] = { 1,-1,0,0,-1,-1,1,1 };
string map[6];
queue<Node> q;

int isAnna(int ey, int ex, int ay, int ax) {
	for (int y = ey - 2; y < ey + 3; y++) {
		for (int x = ex - 2; x < ex + 3; x++) {
			if (y == ay && x == ax) return 1;
		}
	}
	return 0;
};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];
	Node first;
	cin >> first.ey >> first.ex >> first.ay >> first.ax;
	first.t = 0;
	q.push({ first });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (now.ey == now.ay && now.ex == now.ax) {
			cout << now.t << " sec";
			return 0;
		}

		if (isAnna(now.ey, now.ex, now.ay, now.ax)) idxMagic = 4;
		else idxMagic = 8;

		for (int i = 0; i < idxMagic; i++) {
			int nEy = now.ey + eDrY[i];
			int nEx = now.ex + eDrX[i];
			int nt = now.t + 1;
			if (nEy < 0 || nEx < 0 || nEy >= N || nEx >= N) continue;
			if (map[nEy][nEx] == '#') continue;
			for (int j = 0; j < 5; j++) {
				int nAy = now.ay + aDrY[j];
				int nAx = now.ax + aDrX[j];
				if (nAy < 0 || nAx < 0 || nAy >= N || nAx >= N) continue;
				if (map[nAy][nAx] == '#') continue;
				if (nEy == nAy && nEx == nAx) {
					cout << nt << " sec";
					return 0;
				}
				q.push({ nEy,nEx,nAy,nAx,nt });
			}
		}
	}
	return 0;
}