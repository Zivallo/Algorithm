#include <iostream>
#include <vector>
using namespace std;

int N, start, target;
int amat[100][100], used[100];
int maxCost = -1, minCost = 999;

void DFS(int now, int sum) {
	if (now == target) {
		if (sum > maxCost) maxCost = sum;
		if (sum < minCost) minCost = sum;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (amat[now][i] == 0) continue;
		int next = i;
		if (used[next] == 1) continue;
		used[next] = 1;
		DFS(next, sum + amat[now][i]);
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
	cin >> start >> target;
	used[start] = 1;
	DFS(start, 0);

	cout << minCost << "\n" << maxCost;

	return 0;
}