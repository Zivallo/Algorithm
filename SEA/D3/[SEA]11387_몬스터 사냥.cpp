#include<iostream>
using namespace std;
int T, D, L, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> D >> L >> N; long long r = 0;
		for (int n = 0; n < N; n++) {
			r += D + D * n * L / 100;
		}
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