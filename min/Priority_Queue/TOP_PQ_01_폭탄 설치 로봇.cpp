#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y, x;
	int num;
};
bool operator< (Node v, Node t) {
	return t.num < v.num;
}
priority_queue<Node> pq;
int map[1001][1001], used[1001][1001];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
int N, M;

void boom() {
	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int num = pq.top().num;
		pq.pop();
		if (used[y][x] == 1) continue;
		else {
			cout << num << '\n';
			used[y][x] = 1;
			for (int i = 0; i < 4; i++) {
				int ny = y + drY[i];
				int nx = x + drX[i];
				if (ny < 0 || nx < 0 || ny>1000 || nx>1000) continue;
				used[ny][nx] = 1;
			}
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		int cmd, y, x;
		cin >> cmd;
		if (cmd == 0) boom();
		else {
			cin >> y >> x;
			pq.push({ y,x,cmd });
		}
	}
	return 0;
}