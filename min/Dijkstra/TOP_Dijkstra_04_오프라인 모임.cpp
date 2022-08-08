#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int to;
	int cost;
};
bool operator< (Node v, Node t) {
	return t.cost < v.cost;
}

int N, M, P, used[1001][1001], cost[1001][1001];
vector<vector<Node>> alist(1001);
priority_queue<Node> pq;

int main() {
	cin >> N >> M >> P;
	for (int i = 0; i < M; i++) {
		int from, to, cost1;
		cin >> from >> to >> cost1;
		alist[from].push_back({ to,cost1 });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cost[i][j] = 2134567890;
		}
	}
	for (int i = 1; i <= N; i++) {
		pq.push({ i,0 });
		cost[i][i] = 0;

		while (!pq.empty()) {
			int now = pq.top().to;
			int nowCost = pq.top().cost;
			pq.pop();

			if (used[i][now] == 1) continue;
			used[i][now] = 1;

			for (int j = 0; j < alist[now].size(); j++) {
				int next = alist[now][j].to;
				int nextCost = alist[now][j].cost;
				if (cost[i][next] < cost[i][now] + nextCost) continue;
				cost[i][next] = cost[i][now] + nextCost;
				pq.push({ next,cost[i][next] });
			}
		}
	}
	int max = -1;
	for (int i = 1; i <= N; i++) {
		int temp = cost[i][P] + cost[P][i];
		if (max < temp) max = temp;
	}
	cout << max;
	return 0;
}