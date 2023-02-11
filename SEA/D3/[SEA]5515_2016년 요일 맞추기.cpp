#include <iostream>
using namespace std;
int T, M, D;
int rast[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int yoil[13][32];

void init() {
	int yoilidx = 4;
	for (int m = 1; m < 13; m++) {
		for (int d = 1; d <= rast[m]; d++) {
			yoil[m][d] = (yoilidx %= 7);
			yoilidx++;
		}
	}
}
void solve() {
	init();
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> M >> D;
		cout << "#" << t << " " << yoil[M][D] << "\n";
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