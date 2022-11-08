#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node {
	int y, x;
	int sec;
};
int used[2][100002], N, K;
char bridge[2][100002];
queue<Node> q;
int dr[3] = { 1, 0,-1 };
int drJump[3] = { 0,1,0 };

int isComplete() {
	while (!q.empty()) {
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowSec = q.front().sec;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nextY = (nowy + (i % 2)) % 2; // i가 짝수일 때 y그대로, 홀수일때 0->1, 1->0
			int nextX = nowx + dr[i] + K * drJump[i];
			int nSec = nowSec + 1;
			if (nextX >= N) return 1;
			if (nextX <= nowSec || nextX >= N) continue;
			if (bridge[nextY][nextX] != '1') continue;
			if (used[nextY][nextX] == 1) continue;
			used[nextY][nextX] = 1;
			q.push({ nextY,nextX,nSec });
		}
	}
	return 0;
}

int main() {
	cin >> N >> K;
	for (int y = 0; y < 2; y++) {
		cin >> bridge[y];
	}
	q.push({ 0,0,0 });
	if (isComplete()) cout << 1;
	else cout << 0;
	return 0;
}