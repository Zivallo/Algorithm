#include <iostream>
using namespace std;

int N, amat[13][13], used[13];
int minCost = 999;

void DFS(int lev, int now, int sum) {
	if (lev == N) {
		if (sum < minCost) minCost = sum;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (amat[now][i] == 0) continue;
		int next = i;
		if (lev == N-1 && next == 0) {
			used[0] = 1;
			DFS(lev + 1, 0, sum + amat[now][0]);
			used[0] = 0;
		}
		if (used[next] == 1) continue;
		if (next == 0) continue;
		used[next] = 1;
		DFS(lev + 1, next, sum + amat[now][next]);
		used[next] = 0;
	}
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> amat[y][x];
		}
	}
	DFS(0, 0, 0);
	cout << minCost;

	return 0;
}