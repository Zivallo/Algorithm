#include <iostream>
using namespace std;
int n, memo[200];
int map[200];

int getScore(int n) {
	if (n < 0) return -21e8;
	if (memo[n] != -21e8) return memo[n];

	int a = getScore(n - 2) + map[n];
	int b = getScore(n - 7) + map[n];
	int maxVal = max(a, b);
	memo[n] = maxVal;

	return maxVal;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	for (int i = 1; i <= n + 7; i++) {
		memo[i] = -21e8;
	}
	int maxVal = -21e8;
	for (int i = n + 1; i <= n + 5; i++) {
		int temp = getScore(i);
		maxVal = max(maxVal, temp);
	}
	cout << maxVal;
	return 0;
}