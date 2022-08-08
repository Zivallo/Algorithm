#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int y, x;
	int cost;
};
bool operator< (Node v, Node t) {
	return t.cost < v.cost;
}
priority_queue<Node> pq;
int amat[1000][1000], Y, X, N;
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
int P_ro[1000][1000], used[1000][1000];

int main() {
	cin >> Y >> X >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> amat[y][x];
			if (amat[y][x] == -1) continue;
			P_ro[y][x] = 2134567890;
		}
	}
	pq.push({ Y,X,amat[Y][X] });
	P_ro[Y][X] = amat[Y][X];

	while (!pq.empty()) {
		int nowY = pq.top().y;
		int nowX = pq.top().x;
		//int nowCost = pq.top().cost;
		pq.pop();

		if (used[nowY][nowX] == 1) continue;
		used[nowY][nowX] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = nowY + drY[i];
			int nx = nowX + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (amat[ny][nx] == -1) continue;
			if (P_ro[ny][nx] < P_ro[nowY][nowX] + amat[ny][nx]) continue;
			P_ro[ny][nx] = P_ro[nowY][nowX] + amat[ny][nx];
			pq.push({ ny,nx,P_ro[ny][nx] });
		}
	}
	int maxVal = -1, maxidxY = 0, maxidxX = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (maxVal < P_ro[y][x]) {
				maxVal = P_ro[y][x];
				maxidxY = y;
				maxidxX = x;
			}
		}
	}
	cout << P_ro[maxidxY][maxidxX];

	return 0;
}