#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int result, N;
int area[15], popul[15];
vector<int>Node[15];

void input() {
	result = 21e8;
	int cnt, next;
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> popul[i];
	for (int i = 1; i <= N; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> next;
			Node[i].push_back(next);
		}
	}
}
int isPossi(int tar) {
	int areaCnt = 0, cnt = 1, start = 0;
	int used[15] = { 0 };
	queue<int> q;
	for (int i = 1; i <= N; i++) if (area[i] == tar) {
		areaCnt++;
		start = i;
	}
	q.push(start);
	used[start] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < Node[now].size(); i++) {
			int next = Node[now][i];
			if (area[next] != tar) continue;
			if (used[next] == 1)continue;
			used[next] = 1;
			cnt++;
			q.push(next);
		}
	}
	if (cnt == areaCnt) return 1;
	else return 0;
}
int getCha(int a, int b) {
	if (a > b) return a - b;
	else return b - a;
}
int cntPop(int tar) {
	int pop = 0;
	for (int i = 1; i <= N; i++)if (area[i] == tar)pop += popul[i];
	return pop;
}
void dfs(int lev) {
	if (lev == N+1) {
		int flag0 = isPossi(0);
		int flag1 = isPossi(1);
		if (flag0 && flag1) {
			int popul0 = cntPop(0);
			int popul1 = cntPop(1);
			int cha = getCha(popul0, popul1);
			if (result > cha) result = cha;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		area[lev] = i;
		dfs(lev + 1);
		area[lev] = 0;
	}
}
void solve() {
	input();
	dfs(1);
	if (result == 21e8) result = -1;
	cout << result << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}