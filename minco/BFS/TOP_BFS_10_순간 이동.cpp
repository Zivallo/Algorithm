#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int now;
	int sec;
};
queue<Node> q;
int N, M, used[100001];
int drF[3] = { 1,1,2 };
int drR[3] = { 1,-1,0 };

int getMinTime() {
	while (!q.empty()) {
		int now = q.front().now;
		int nowSec = q.front().sec;
		q.pop();
		if (now == M) return nowSec;
		for (int i = 0; i < 3; i++) {
			int next = drF[i] * now + drR[i];
			if (next < 0 || next > 100000) continue;
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push({ next, nowSec + 1 });
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	used[N] = 1;
	q.push({ N,0 });
	cout << getMinTime();
	return 0;
}