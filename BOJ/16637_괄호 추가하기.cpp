#include <iostream>
using namespace std;
int N;
char cmd[30];
long long dp[30], result;
long long dpmini[30];
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> cmd[i];
}
long long calc(char oper, long long a, long long b) {
	if (oper == '+') return a + b;
	else if (oper == '*') return a * b;
	else if (oper == '-') return a - b;
	return 0;
}
void solve() {
	input();
	dp[1] = dpmini[1] = cmd[1] - '0';
	dp[3] = dpmini[3] = calc(cmd[2], cmd[1] - '0', cmd[3] - '0');
	for (int i = 5; i <= N; i += 2) {
		long long garo = calc(cmd[i - 1], cmd[i - 2] - '0', cmd[i] - '0');
		long long a = calc(cmd[i - 3], dp[i - 4], garo);
		long long b = calc(cmd[i - 1], dp[i - 2], cmd[i] - '0');
		long long c = calc(cmd[i - 3], dpmini[i - 4], garo);
		long long d = calc(cmd[i - 1], dpmini[i - 2], cmd[i] - '0');
		dp[i] = max(a, max(b, max(c, d)));
		dpmini[i] = min(a, min(b, min(c, d)));
	}
	result = dp[N];
	cout << result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}