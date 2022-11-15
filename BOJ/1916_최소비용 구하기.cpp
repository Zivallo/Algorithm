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

priority_queue<Node> pq;
vector < vector<Node>> alist(1001);
int used[1001], cost[1001];
int N, M, snode, lnode;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost1;
		cin >> from >> to >> cost1;
		alist[from].push_back({ to,cost1 });
	}
	for (int i = 1; i <= N; i++) cost[i] = 2134567890;

	cin >> snode >> lnode;

	pq.push({ snode, 0 });
	cost[snode] = 0;

	while (!pq.empty()) {
		int now = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();

		if (used[now] == 1) continue;
		used[now] = 1;

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i].to;
			int nextCost = alist[now][i].cost;
			if (cost[next] < cost[now] + nextCost) continue;
			cost[next] = cost[now] + nextCost;
			pq.push({ next, cost[next] });
		}
	}
	cout << cost[lnode];

	return 0;
}