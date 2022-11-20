#include <iostream>
using namespace std;
int T, N, L, r;
int sk[22][2];

void dfs(int l, int s, int k,int start) {
	if (start == N) return;
	for (int i = start; i < N; i++) {
		if (k + sk[i][1] > L) continue;
		if (k + sk[i][1] <= L && s + sk[i][0] > r)r = s + sk[i][0];
		dfs(l + 1, s + sk[i][0], k + sk[i][1], i + 1);
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		r = 0;
		cin >> N >> L;
		for (int i = 0; i < N; i++)cin >> sk[i][0] >> sk[i][1];
		dfs(0, 0, 0, 0);
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