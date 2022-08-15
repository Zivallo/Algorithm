#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector < vector<int>> alist(11);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	int start, K;
	int used[11] = { 0, };

	cin >> start >> K;
	queue<int> q;
	q.push(start);
	used[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i];
			if (used[next] > 0) continue;
			used[next] = used[now] + 1;
			q.push(next);
		}
	}
	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		if (used[i] != 0 && used[i] <= K + 1) cnt++;
	}
	cout << cnt;
	return 0;
}