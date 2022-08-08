#include <iostream>
#include <vector>
using namespace std;
int cnt, N, M;
int used[101];
vector<vector<int>> alist(101);

void run(int now) {

	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (next > N) continue;
		if (used[next] == 1) continue;
		used[next] = 1;
		cnt++;
		run(next);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	used[1] = 1;
	run(1);
	cout << cnt;
}