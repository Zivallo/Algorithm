#include <iostream>
using namespace std;
int N, n[12], o[4];
long long maxi = -21e8, mini = 21e8;

long long calc(long long a, long long b, int op) {
	if (op == 0) return a + b;
	if (op == 1) return a - b;
	if (op == 2) return a * b;
	if (op == 3) return a / b;
}
void dfs(int l, long long s) {
	if (l == N) {
		if (s > maxi)maxi = s;
		if (s < mini)mini = s;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (o[i] == 0)continue;
		o[i]--;
		dfs(l + 1, calc(s, n[l], i));
		o[i]++;
	}
}
void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> n[i];
	for (int i = 0; i < 4; i++)cin >> o[i];
	dfs(1, n[0]);
	cout << maxi << "\n" << mini;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}