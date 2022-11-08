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
int N, M;
vector<vector<Node>> alist(20000);
priority_queue<Node> pq;
int price[20000], used[20000];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		alist[from].push_back({ to,cost });
	}
	for (int i = 0; i < N; i++) price[i] = 2134567890;

	pq.push({ 0,0 });
	price[0] = 0;

	while (!pq.empty()) {
		int now = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();

		if (used[now] == 1) continue;
		used[now] = 1;

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i].to;
			int nextCost = alist[now][i].cost;
			if (price[next] < price[now] + nextCost) continue;
			price[next] = price[now] + nextCost;
			pq.push({ next, price[next] });
		}
	}
	if (price[N - 1] == 2134567890) cout << "impossible";
	else cout << price[N - 1];

	return 0;
}