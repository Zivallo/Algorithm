#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int now;
	int dist;
};
vector<vector<int>> alist(200001);
int dist[200001], N, M, K, P, flag;
queue<Node> q;

void setDist() {
	while (!q.empty()) {
		int now = q.front().now;
		int nowDist = q.front().dist;
		q.pop();

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i];
			int nDist = nowDist + 1;
			if (dist[next] > 0) continue;
			if (next == P) continue;
			dist[next] = nDist;
			q.push({ next,nDist });
		}
	}
}

int main() {
	cin >> N >> M >> K >> P;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
	}
	q.push({ P,0 });
	setDist();
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << '\n';
			flag = 1;
		}
	}
	if (flag == 0) cout << -1;
	return 0;
}