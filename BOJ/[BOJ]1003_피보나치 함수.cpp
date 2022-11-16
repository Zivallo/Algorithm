#include <iostream>
using namespace std;
int T, fibo[41][2];
void mkfibo() {
	for (int i = 2; i < 41; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}
}
void solve() {
	fibo[0][0] = 1, fibo[0][1] = 0;
	fibo[1][0] = 0, fibo[1][1] = 1;
	mkfibo();
	cin >> T; for (int t = 1; t <= T; t++) {
		int x; cin >> x;
		cout << fibo[x][0] << " " << fibo[x][1] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}