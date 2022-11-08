#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<vector<int>> alist(11);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	int avoid;
	cin >> avoid;
	int used[11] = { 0, };
	int cnt[11] = { 0, };

	queue<int> q;
	q.push(1);
	used[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i];
			if (next == avoid) continue;
			if (used[next] == 1) continue;
			used[next] = 1;
			cnt[next] = cnt[now] + 1;
			q.push(next);
		}
	}
	if (cnt[N]) cout << cnt[N];
	else cout << -1;
	return 0;
}