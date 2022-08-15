#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int to;
	int cost;
};
vector<vector<Node>> alist(100001);
int robot1[100001], robot2[100001];
int r1, r2, minCost = 2134567890, N;

void setR1Cost(int now, int cost) {
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i].to;
		int nCost = cost + alist[now][i].cost;
		if (robot1[next] > 0) continue;
		if (next == r1) continue;
		robot1[next] = nCost;
		setR1Cost(next, nCost);
	}
}
void setR2Cost(int now, int cost) {
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i].to;
		int nCost = cost + alist[now][i].cost;
		if (robot2[next] > 0) continue;
		if (next == r2) continue;
		robot2[next] = nCost;
		setR2Cost(next, nCost);
	}
}

int main() {
	cin >> N >> r1 >> r2;
	for (int i = 0; i < N - 1; i++) {
		int from = 0, to = 0, cost = 0;
		cin >> from >> to >> cost;
		alist[from].push_back({ to,cost });
		alist[to].push_back({ from,cost });
	}
	setR1Cost(r1, 0);
	setR2Cost(r2, 0);
	for (int i = 1; i <= N; i++) {
		int sum = robot1[i] + robot2[i];
		if (minCost > sum) minCost = sum;
		for (int j = 0; j < alist[i].size(); j++) {
			int sum = robot1[i] + robot2[alist[i][j].to];
			if (minCost > sum) minCost = sum;
		}
	}
	cout << minCost;
	return 0;
}