#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int to;
	int cost;
};
bool operator< (Node v, Node t) {
	return t.cost < v.cost;
}
vector<vector<Node>> alist(100001);
priority_queue<Node> pq;
int C, P, K, A, B;
int cost[3][100001], used[3][100001];

void dijkstra(int snode, int idx) {
	pq.push({ snode,0 });
	cost[idx][snode] = 0;

	while (!pq.empty()) {
		int now = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();

		if (used[idx][now] == 1) continue;
		used[idx][now] = 1;

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i].to;
			int nextCost = alist[now][i].cost;
			if (cost[idx][next] < cost[idx][now] + nextCost) continue;
			cost[idx][next] = cost[idx][now] + nextCost;
			pq.push({ next, cost[idx][next] });
		}
	}
}

int main() {
	cin >> C >> P >> K >> A >> B;
	for (int i = 0; i < C; i++) {
		int from, to, cost1;
		cin >> from >> to >> cost1;
		alist[from].push_back({ to,cost1 });
		alist[to].push_back({ from,cost1 });
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 1; x <= P; x++) {
			cost[y][x] = 2134567890;
		}
	}
	dijkstra(K, 0);
	dijkstra(A, 1);
	dijkstra(B, 2);
	int distA = cost[0][A] + cost[1][B];
	int distB = cost[0][B] + cost[2][A];
	if (distA >= distB) cout << distB;
	else cout << distA;

	return 0;
}