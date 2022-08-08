#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int to, cost;
};
bool operator< (Node v, Node t) {
	return t.cost < v.cost;
}
priority_queue<Node> pq;
vector<vector<Node>> alist(1001);
int N, M, K, snode, lnode;
int price[30000][1001], used[30000][1001];
int plusVal;


int main() {
	cin >> N >> M >> K >> snode >> lnode;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		alist[from].push_back({ to,cost });
		alist[to].push_back({ from,cost });
	}
	for (int i = 0; i < K + 1; i++) {
		if (i > 0) {
			int temp;
			cin >> temp;
			plusVal += temp;
		}
		for (int j = 1; j <= N; j++) price[i][j] = 2134567890;

		pq.push({ snode,0 });
		price[i][snode] = 0;

		while (!pq.empty()) {
			int now = pq.top().to;
			int nowCost = pq.top().cost;
			pq.pop();

			if (used[i][now] == 1) continue;
			used[i][now] = 1;

			for (int k = 0; k < alist[now].size(); k++) {
				int next = alist[now][k].to;
				int nextCost = alist[now][k].cost + plusVal;
				if (price[i][next] < price[i][now] + nextCost) continue;
				price[i][next] = price[i][now] + nextCost;
				pq.push({ next,price[i][next] });
			}
		}
		cout << price[i][lnode] << '\n';
	}
	return 0;
}