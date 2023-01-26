#include <iostream>
using namespace std;
int T, N, D, town[300100];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> D; int r = 0, c = 0;
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			if (tmp == 0)c++;
			if (tmp == 1) {
				r += (c / D);
				c = 0;
			}
		}
		r += (c / D);
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