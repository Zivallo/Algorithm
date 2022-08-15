#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int to;
	int value;
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<Node>> alist(100);
	for (int i = 0; i < M; i++) {
		int from, to, value;
		cin >> from >> to >> value;
		alist[from].push_back({ to, value });
		alist[to].push_back({ from, value });
	}
	queue<int> q;
	q.push(0);
	int used[100] = { 0, };
	used[0] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i].to;
			if (used[next] > 0) continue;
			used[next] = used[now] + alist[now][i].value;
			q.push(next);
		}
	}
	for (int n = 1; n < N; n++) {
		if (used[n] > 0 && used[n] <= K + 1) cout << n << " ";
	}
	return 0;
}