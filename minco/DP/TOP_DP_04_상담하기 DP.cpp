#include <iostream>
using namespace std;

int list[2][110], N, memo[110];

int getMaxCost(int n) {
	if (n == N) return list[1][N];
	if (memo[n] != 0) return memo[n];

	int maxCost = -1;
	for (int i = n + list[0][n]; i <= N; i++) {
		int temp = getMaxCost(i) + list[1][n];
		maxCost = max(maxCost, temp);
	}
	memo[n] = maxCost;
	return maxCost;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[0][i] >> list[1][i];
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		int temp = getMaxCost(i);
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}