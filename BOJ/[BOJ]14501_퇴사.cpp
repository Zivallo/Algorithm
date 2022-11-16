#include <iostream>
using namespace std;
int N, result;
int T[20], P[20], dpval[20];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
		dpval[i] = -1;
	}
}
int dp(int day) {
	if (day == N) return 0;
	if (day > N)return -2;
	if (dpval[day] != -1) return dpval[day];
	int ans = 0;
	if (dp(day + T[day]) == -2) ans = dp(day + 1);
	else ans = max(dp(day + T[day]) + P[day], dp(day + 1));
	dpval[day] = ans;
	return dpval[day];
}
void solve() {
	input();
	result = dp(0);
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