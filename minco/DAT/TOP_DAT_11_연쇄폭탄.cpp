#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	int num;
};
int used[1000][1000], N;
priority_queue<Node> pq;
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

bool operator< (Node v, Node t) {
	return t.num < v.num;
}

int used_check() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (used[y][x] == 0) return 0;
		}
	}
	return 1;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int temp;
			cin >> temp;
			pq.push({ y,x,temp });
		}
	}
	int times = 0;
	while (!used_check()) {
		int yt = pq.top().y;
		int xt = pq.top().x;
		times = pq.top().num;
		pq.pop();
		if (used[yt][xt] == 1) continue;
		used[yt][xt] = 1;
		for (int i = 0; i < 4; i++) {
			int ny = yt + drY[i];
			int nx = xt + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
		}
	}
	cout << times << "ÃÊ";

	return 0;
}