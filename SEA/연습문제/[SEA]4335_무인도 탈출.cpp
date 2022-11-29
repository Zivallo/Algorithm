#include <iostream>
using namespace std;
int T, N;
int u[21][1 << 20][3], b[21][3];

void swap(int& i1, int& i2) {
	int tmp = i1;
	i1 = i2;
	i2 = tmp;
}
int max(int i1, int i2) {
	return i1 > i2 ? i1 : i2;
}
void init() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 1 << N; j++) {
			for (int k = 0; k < 3; k++)u[i][j][k] = 0;
		}
	}
}
int result(int now, int mode, int r, int c, int visit) {
	int& ret = u[now][visit][mode];
	if (ret) return ret;

	for (int i = 1; i <= N; i++) {
		if (visit & (1 << (i - 1))) continue;
		int nv = visit | 1 << (i-1);
		if (r >= b[i][0] && c >= b[i][1]) {
			ret = max(ret, b[i][2] + result(i, 2, b[i][0], b[i][1], nv));
		}
		if (r >= b[i][1] && c >= b[i][2]) {
			ret = max(ret, b[i][0] + result(i, 0, b[i][1], b[i][2], nv));
		}
		if (r >= b[i][0] && c >= b[i][2]) {
			ret = max(ret, b[i][1] + result(i, 1, b[i][0], b[i][2], nv));
		}
	}
	return ret;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		init();
		for (int i = 1; i <= N; i++) {
			cin >> b[i][0] >> b[i][1] >> b[i][2];
			if (b[i][0] > b[i][1]) swap(b[i][0], b[i][1]);
			if (b[i][1] > b[i][2]) swap(b[i][1], b[i][2]);
			if (b[i][0] > b[i][1]) swap(b[i][0], b[i][1]);
		}
		cout << "#" << t << " " << result(0, 0, 21e8, 21e8, 0) << "\n";
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}