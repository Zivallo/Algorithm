#include <iostream>
#include <algorithm>
using namespace std;
int T, N, L, r;
int a[22];

void dfs(int start, int s) {
	if (start == N)return;
	for (int i = start; i < N; i++) {
		if (s + a[i] > L)break;
		if (s + a[i] == L) r++;
		dfs(i + 1, s + a[i]);
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> L; r = 0;
		for (int i = 0; i < N; i++)cin >> a[i];
		sort(a, a + N);
		dfs(0, 0);
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}