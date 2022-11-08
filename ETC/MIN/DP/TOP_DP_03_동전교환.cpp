#include <iostream>
using namespace std;

int T, n;
int coin[11], memo[3100];

int getCnt(int t) {
	if (t == 0)return 0;
	if (t < 0) return 21e8;
	if (memo[t] != -21e8) return memo[t];

	int minCnt = 21e8;
	for (int i = 0; i < n; i++) {
		int temp = getCnt(t - coin[i]) + 1;
		minCnt = min(minCnt, temp);
	}

	memo[t] = minCnt;
	return minCnt;
}

int main() {
	cin >> T >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = 0; i < T + 1; i++) {
		memo[i] = -21e8;
	}
	int ans = getCnt(T);
	if (ans == 21e8) {
		cout << "impossible";
		return 0;
	}
	cout << ans;
	return 0;
}